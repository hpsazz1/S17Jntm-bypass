# mYjJYFSJwydN.exe 破解方案

> 专注目标：`mYjJYFSJwydN.exe` (VMP 3.x) + `FBrowserVIP.dll` (无壳验证SDK)
> 基于 2026-07-01 目录二进制分析

---

## 一、程序架构总览

```
mYjJYFSJwydN.exe (x86, VMP 3.x, ~21MB)
  │
  ├── PE结构: .text / .rdata / .data / .rsrc
  │           .svmp1 (VMP导入混淆) / .svmp2 (VMP代码虚拟化,熵7.84)
  │           .svmp3 (VMP代码虚拟化,熵7.59)
  │           + 约1.3MB overlay（尾部附加数据）
  │
  ├── 编译: 2026-06-13, 易语言/MFC, 管理员权限
  │
  ├── 导入: ADVAPI32, WS2_32, USER32, KERNEL32, GDI32, SHELL32等
  │
  ├── LibPath.ini → 定位 CEFlib/
  │     [FBrowserCEF3lib]
  │     Path=\CEFlib\
  │
  └── 依赖 CEFlib/:
        ├── FBrowserVIP.dll  ← 核心许可验证（无壳）
        ├── FBrowserCEF3lib.dll  ← CEF 封装层
        └── libcef.dll  ← Chromium CEF 引擎 (~155MB)
```

---

## 二、FBrowserVIP.dll — 验证组件的完整分析

**这是整个系统中唯一无保护壳的攻击面。** 它是一个商业在线许可验证 SDK，内部集成了 Crypto++ 和 OpenSSL，但导出接口完全开放。

| 属性 | 值 |
|------|------|
| 路径 | `CEFlib/FBrowserVIP.dll` |
| 大小 | 4,021,760 bytes |
| 架构 | x86 PE32 |
| 保护 | **无**（.text 熵 6.86，正常编译代码） |
| 导出函数 | **131 个**（全部命名可见） |
| 导入 | libcef.dll, crypt32.dll, bcrypt.dll, WS2_32, ADVAPI32 |
| 静态链接 | Crypto++ (AES-CBC, RSA-OAEP, SHA), OpenSSL |

### 2.1 关键验证 API

#### 在线许可控制（验证核心）

| 导出函数 | 地址 | 功能 |
|---------|------|------|
| `FBroOnlineLicenseControl_SetKey` | 0x083250 | **【入口】** 设置授权 Key |
| `FBroOnlineLicenseControl_GetError` | 0x083680 | **【出口】** 获取错误码（0=成功） |
| `FBroOnlineLicenseControl_GetShowLicenseType` | 0x083320 | 授权类型（试用/正式/黑名单） |
| `FBroOnlineLicenseControl_GetShowLicenseStartDate` | 0x0833B0 | 授权开始日期 |
| `FBroOnlineLicenseControl_GetShowLicenseEndDate` | 0x083440 | 授权结束日期（过期返回过期时间） |
| `FBroOnlineLicenseControl_GetShowLicenseFunction` | 0x083560 | 授权功能列表（位掩码或字符串） |
| `FBroOnlineLicenseControl_GetShowLicenseDevTool` | 0x0834D0 | 开发者工具权限 |
| `FBroOnlineLicenseControl_GetShowLicenseSysVersion` | 0x0835F0 | 系统版本标识 |

#### 浏览器/机器信息

| 导出函数 | 地址 | 功能 |
|---------|------|------|
| `FBroBrowser_GetMachineCode` | 0x098C30 | **机器码（硬件绑定用）** |
| `FBroBrowser_GetExpirationTime` | 0x0A70B0 | 过期时间戳 |
| `FBroBrowser_GetRegistrationTime` | 0x0A70C0 | 注册时间戳 |
| `FBroBrowser_GetVIPControl` | 0x055CC0 | 获取 VIP 控制接口指针 |
| `FBroBrowser_IsLicenceKey` | 0x0A70A0 | **是否已授权（true/false）** |
| `FBroBrowser_SetLicenceKey` | 0x0A7090 | 设置授权 Key（字符串） |
| `FBroBrowser_GetVersionStr` | 0x0A70D0 | 版本号字符串 |
| `FBroBrowser_GetFunctionStr` | 0x0A70E0 | 功能描述字符串 |

#### 浏览器指纹控制（环境伪装）

| 导出函数 | 功能 |
|---------|------|
| `FBroVIPControl_SetDisableDebugger` | 禁止 F12 开发者工具（反调试） |
| `FBroVIPControl_SetDisableConsoleDebug` | 禁止控制台输出 |
| `FBroVIPControl_EnableWebsocketClientHook` | **WebSocket Hook 能力** |
| `FBroVIPControl_SetS5Auth` / `FBroVIPGlobal_SetS5Auth` | S5 代理认证配置 |
| `FBroVIPControl_*` (SetVir\*) | 浏览器环境变量全部可伪造（UA、平台、语言、时区、WebRTC IP、Canvas指纹等） |

### 2.2 DLL 内部依赖

```
FBrowserVIP.dll
  ├── libcef.dll (131个导入函数: 字符串操作/JSON解析/值类型等)
  ├── crypt32.dll (Windows 加密API)
  ├── bcrypt.dll (Windows BCrypt)
  ├── ntdll.dll / kernel32 / advapi32 / user32
  ├── 静态 Crypto++ (AES-CBC 加解密, RSA-OAEP, SHA1/SHA256)
  └── 静态 OpenSSL (SSL/TLS, 证书验证, 哈希)
```

### 2.3 推论

FBrowserVIP.dll 是一个典型的**第三方在线验证 SDK**：
1. 主程序调用 `SetKey(用户输入的Key)` → DLL 内部处理验证
2. 验证通过 → 本地缓存授权状态（LicenseType/EndDate）
3. 主程序后续调用 `IsLicenceKey` 或 `GetError` 检查结果
4. 可预见调用链：`SetKey` → `GetError`(轮询) → `IsLicenceKey`(判断)

---

## 三、VMP 保护的限制边界

基于 FlyingStick 项目中 VMP 保护的实测经验：

| 操作 | VMP 是否检测 |
|------|------------|
| ✅ DLL 文件替换（劫持目录中的 DLL） | **不检测** |
| ✅ ProcMon / Wireshark 被动监控 | **不检测** |
| ✅ 修改程序目录的配置文件/INI | **不检测** |
| ✅ IAT Hook（修改进程导入表） | **不检测**（VMP 混淆自身导入但不扫 IAT） |
| ⚠️ 修改 .svmp2/.svmp3 加密节区 | 会检测（VMP 解密时校验） |
| ⚠️ Cheat Engine 运行时内存修改 | 可能检测（VMP 有内存扫描） |
| ❌ 附加用户态调试器 (x64dbg) | 触发反调试 |
| ❌ Inline Hook（修改系统 DLL 入口） | VMP 不主动检测，但 FBrowserVIP 可能内含检测 |

**关键结论：DLL 劫持不触发 VMP 保护。**

---

## 四、破解方案

### 4.1 主方案：FBrowserVIP.dll 劫持 + API Hook

**原理：** 制作伪装的 `FBrowserVIP.dll` 替换原文件，接管验证 API 返回值。

```
mYjJYFSJwydN.exe ──→ FBrowserVIP.dll (代理)
                              │
                              ├── FBroOnlineLicenseControl_SetKey
                              │     → 记录 Key 并「成功」
                              │
                              ├── FBroOnlineLicenseControl_GetError
                              │     → 返回 0 (无错误)
                              │
                              ├── FBroOnlineLicenseControl_GetShowLicenseType
                              │     → 返回 "正式版" / 整数 2
                              │
                              ├── FBroOnlineLicenseControl_GetShowLicenseEndDate
                              │     → 返回 2099-12-31
                              │
                              ├── FBroBrowser_IsLicenceKey
                              │     → 返回 true
                              │
                              ├── FBroBrowser_GetMachineCode
                              │     → 返回固定机器码（或透传）
                              │
                              └── 其余 125 个导出函数
                                    → 转发到原始 FBrowserVIP_original.dll
```

#### 实施步骤

**Step 1 — 反编译验证原始逻辑**
- 用 IDA + Hex-Rays 打开 `FBrowserVIP.dll`
- 重点反编译 8 个关键验证函数
- 分析 `SetKey` 的参数格式（字符串长度/编码要求）
- 分析 `GetError` 的错误码定义（0=成功，负数=各类错误）
- 确认 `IsLicenceKey` 的内部检查逻辑

**Step 2 — 制作代理 DLL**
- 重命名原始 DLL 为 `FBrowserVIP_original.dll`
- 编写代理 DLL，导出全部 131 个函数
- 非验证函数 → LoadLibrary("FBrowserVIP_original.dll") + GetProcAddress 转发
- 验证函数 → 直接返回硬编码的"成功"值
- 用 Visual Studio 2022 (cl.exe) 编译

**Step 3 — 测试运行**
- 将代理 DLL 放入 `CEFlib/` 目录
- 启动 mYjJYFSJwydN.exe
- ProcMon 追踪 DLL 加载情况
- 观察程序行为（验证是否已被绕过）

**代码示例（伪代码）：**

```c
// FBrowserVIP_proxy.c — 核心逻辑

#include <windows.h>

// 原始 DLL 句柄
HMODULE g_hOriginal = NULL;

BOOL WINAPI DllMain(HINSTANCE hinst, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        // 加载原始 DLL
        g_hOriginal = LoadLibraryA("FBrowserVIP_original.dll");
    }
    return TRUE;
}

// ── 验证 API 拦截 ──

int __stdcall FBroOnlineLicenseControl_SetKey(const char* key) {
    // 1. 记录用户输入的 Key（便于分析）
    OutputDebugStringA(key);
    // 2. 调用原始 DLL 实际执行（观察行为）
    // 或直接返回成功
    return 0; // 返回 0 可能表示成功
}

int __stdcall FBroOnlineLicenseControl_GetError() {
    return 0; // 0 = 无错误
}

int __stdcall FBroOnlineLicenseControl_GetShowLicenseType() {
    return 2; // 2 = 正式版
}

long long __stdcall FBroOnlineLicenseControl_GetShowLicenseEndDate() {
    // 返回 2099-12-31 的时间戳
    return 4102444800LL;
}

BOOL __stdcall FBroBrowser_IsLicenceKey() {
    return TRUE;
}

// ── 其余 125 个函数 ── 用转发器模式

// 通用转发函数生成宏
#define FORWARD_FUNC(name) \
    void __stdcall name() { \
        static FARPROC fp = NULL; \
        if (!fp) fp = GetProcAddress(g_hOriginal, #name); \
        if (fp) fp(); \
    }

// 或使用 .def 文件 + pragma 转发到原始 DLL
#pragma comment(linker, "/EXPORT:FBroBrowser_GetExpirationTime=FBrowserVIP_original.FBroBrowser_GetExpirationTime")
// ... 其余导出函数类似
```

#### 风险与应对

| 风险 | 概率 | 应对策略 |
|------|------|---------|
| 主程序不调用 FBrowserVIP.dll | 低 | 先用 ProcMon 确认 |
| VMP 校验 DLL 哈希/签名 | 低 | 若触发，改用 IAT Hook 而非文件替换 |
| SetKey 参数格式特殊 | 中 | 反编译确认参数要求 |
| GetError 返回值含义复杂 | 中 | 追踪原始 DLL 的完整返回路径 |
| 验证结果存储在服务端而非本地 | 低 | 若 DLL 无本地缓存，走备选网络方案 |

### 4.2 备选方案 A：WinDivert 网络驱动层拦截

如果 DLL 劫持无效（主程序不走 FBrowserVIP.dll 验证，而是直接 HTTP 请求），则：

```
适用：验证完全走 HTTP/HTTPS 且不经过 FBrowserVIP.dll
方法：WinDivert 驱动层过滤 TCP 流量
优点：VMP 不检测驱动层操作
缺点：需要驱动安装 + HTTPS 需要中间人证书
```

**步骤：**
1. Wireshark 抓包确认验证 URL 和协议
2. 安装 WinDivert 驱动
3. 编写过滤规则：`tcp and (tcp.SrcPort == 80 or tcp.DstPort == 80)`
4. 将请求转发到本地 Flask 服务器
5. 返回伪造的成功响应

### 4.3 备选方案 B：x64dbg + ScyllaHide + 硬件断点

```
适用：VMP 反调试阻挡了普通调试器
方法：硬件断点（DR0-DR3）绕过 PEB 检测
优点：在 VMP .svmp2 代码运行时也能下断
缺点：门槛极高，成功率低
```

**步骤：**
1. 加载 x64dbg + ScyllaHide 插件
2. 使用硬件断点而非软件断点（INT3）
3. 在 `OutputDebugStringA` 或 `GetLastError` 等 API 设断
4. 单步跟踪验证逻辑

---

## 五、分阶段实施计划

### Phase 1：诊断与信息收集（预计 1-2 天）

| 步骤 | 操作 | 工具 | 预期产出 |
|------|------|------|---------|
| 1.1 | 运行主程序，ProcMon 监控 DLL 加载 | ProcMon | 确认 FBrowserVIP.dll 调用链 |
| 1.2 | 运行主程序，Wireshark 抓包 | Wireshark | 发现验证 URL 和协议格式 |
| 1.3 | 反编译验证 API | IDA + Hex-Rays | SetKey/GetError/IsLicenceKey 完整逻辑 |
| 1.4 | 检查主程序导入表 | DIE / CFF Explorer | 确认是否直接导入 FBrowserVIP.dll |

### Phase 2：DLL 劫持实施（预计 2-3 天）

| 步骤 | 操作 | 产出 |
|------|------|------|
| 2.1 | 编写 .def 文件，列出 131 个导出函数 | `fbro_export.def` |
| 2.2 | 编写代理 DLL C 源码 | `FBrowserVIP_proxy.c` |
| 2.3 | 编译为 x86 DLL | `FBrowserVIP.dll` |
| 2.4 | 备份原始 DLL，放入代理 DLL | 准备测试 |
| 2.5 | 启动测试，观察结果 | 成功/失败报告 |

### Phase 3：迭代优化（预计 1-2 天）

| 问题 | 应对 |
|------|------|
| 程序崩溃 | 检查被忽略的函数是否必须正确实现 |
| 验证未完全绕过 | 逆向更多验证函数，确认遗漏点 |
| DLL 版本不兼容 | 调整导出转发策略 |

### Phase 4：备选方案（仅在 Phase 2 失败时）

| 方案 | 预计时间 |
|------|---------|
| WinDivert 网络驱动拦截 | 3-5 天 |
| x64dbg + 硬件断点 | 5-10 天 |

---

## 六、工具链

| 用途 | 推荐工具 | 说明 |
|------|---------|------|
| PE 分析 | Detect It Easy (DIE) | 查壳、节区分析 |
| 静态反编译 | IDA Pro 8.x + Hex-Rays | 反编译 FBrowserVIP.dll |
| 免费静态分析 | Ghidra 11.x | IDA 免费替代方案 |
| DLL 劫持编译 | VS 2022 (cl.exe, x86) | 编译代理 DLL |
| API Hook 库 | MinHook / Microsoft Detours | 内部 Hook 选用 |
| 网络抓包 | Wireshark + RawCap | RawCap 可回环抓包 |
| 进程监控 | ProcMon (Process Monitor) | DLL 加载/文件/注册表监控 |
| 网络驱动 | WinDivert 2.2+ | 驱动层 TCP 拦截 |
| 调试器 | x64dbg + ScyllaHide | VMP 反调试绕过 |
| 内存修改 | Cheat Engine 7.5+ | 运行时搜索标志位 |

### 编译命令

```cmd
REM VS Developer Command Prompt (x86) 中：
cl /nologo /O2 /GS- /MD /LD FBrowserVIP_proxy.c /link /DEF:fbro_export.def
```

---

## 七、预期结果

| 阶段 | 目标 | 难度 | 成功率 | 时间 |
|------|------|------|--------|------|
| Phase 1 | 诊断确认调用关系 | ⭐ | 95% | 1-2 天 |
| Phase 2 | DLL 劫持绕过验证 | ⭐⭐⭐ | 70% | 2-3 天 |
| Phase 3 | 迭代优化稳定运行 | ⭐⭐ | 80% | 1-2 天 |
| Phase 4 备选 | WinDivert/硬件断点 | ⭐⭐⭐⭐⭐ | 40% | 5-10 天 |

**核心信心来源：** FBrowserVIP.dll 无保护壳、API 可见、VMP 不阻止 DLL 劫持——这三个条件组合让 DLL 劫持成为高概率成功方案。

---

*本文档仅针对 `mYjJYFSJwydN.exe` + `FBrowserVIP.dll`*
*更新日期：2026-07-01*

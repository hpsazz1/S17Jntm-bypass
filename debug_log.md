# mYjJYFSJwydN.exe 破解 — 调试记录

> 项目: S17Jntm-bypass | 仓库: https://github.com/hpsazz1/S17Jntm-bypass

---

## Node 0-2026-07-01 — 项目初始化

### 目标
建立项目结构，备份原始文件，完成方案规划

### 方法
目录分析 → 方案规划 → 文件备份 → Git 初始化

### 操作步骤
1. 分析 S17Jntm1.5 目录结构：mYjJYFSJwydN.exe (VMP 3.x) + FBrowserVIP.dll (无壳验证SDK) + 自定义阵容工具.exe (x64无壳)
2. 排除自定义阵容工具.exe，专注 mYjJYFSJwydN.exe 破解
3. 备份原始文件到 backup/ 目录
4. 删除过时方案文档（网络验证程序破解通用方案.md、目录分析报告与优化方案.md）
5. 写入专注破解方案 mYjJYFSJwydN破解方案.md
6. 创建 public repo: github.com/hpsazz1/S17Jntm-bypass
7. 提交并推送 tag v0.1-init

### 结果
✅ 项目结构就绪

### 标记
- 仓库: https://github.com/hpsazz1/S17Jntm-bypass
- Tag: v0.1-init

### 下一个节点计划
Phase 1 诊断：用 ProcMon 确认 mYjJYFSJwydN.exe 是否加载 FBrowserVIP.dll、Wireshark 抓包确认验证通信

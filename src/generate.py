#!/usr/bin/env python3
"""
Generate dll_proxy.c and dll_proxy.def for FBrowserVIP.dll proxy.

Each forwarding function uses tail-call optimization:
    return g_table[N]();
    Compiler generates: jmp dword ptr [g_table+N]
    No stack manipulation needed, args pass through correctly.

Intercept functions return hardcoded success values.
"""

FUNCS = """
FBroBrowser_GetExpirationTime
FBroBrowser_GetFunctionStr
FBroBrowser_GetMachineCode
FBroBrowser_GetRegistrationTime
FBroBrowser_GetVIPControl
FBroBrowser_GetVersionStr
FBroBrowser_IsLicenceKey
FBroBrowser_SetLicenceKey
FBroDevToolsDOM_disable
FBroDevToolsDOM_discardSearchResults
FBroDevToolsDOM_enable
FBroDevToolsDOM_focusElement
FBroDevToolsDOM_getAttributes
FBroDevToolsDOM_getContainerForNode
FBroDevToolsDOM_getDocument
FBroDevToolsDOM_getOuterHTML
FBroDevToolsDOM_getSearchResults
FBroDevToolsDOM_performSearch
FBroDevToolsDOM_querySelector
FBroDevToolsDOM_querySelectorAll
FBroDevToolsDOM_removeAttribute
FBroDevToolsDOM_removeNode
FBroDevToolsDOM_setAttributeValue
FBroDevToolsDOM_setAttributesAsText
FBroDevToolsDOM_setNodeName
FBroDevToolsDOM_setNodeValue
FBroDevToolsDOM_setOuterHTML
FBroOnlineLicenseControl_GetError
FBroOnlineLicenseControl_GetShowLicenseDevTool
FBroOnlineLicenseControl_GetShowLicenseEndDate
FBroOnlineLicenseControl_GetShowLicenseFunction
FBroOnlineLicenseControl_GetShowLicenseStartDate
FBroOnlineLicenseControl_GetShowLicenseSysVersion
FBroOnlineLicenseControl_GetShowLicenseType
FBroOnlineLicenseControl_SetKey
FBroVIPBountControl
FBroVIPControl_AddDevToolsMessageObserver
FBroVIPControl_AddResourceHandlerChangeData
FBroVIPControl_AddResourceHandlerChangeFile
FBroVIPControl_AddResponseFilterChangeData
FBroVIPControl_ClearAllData
FBroVIPControl_ClearFingerCount
FBroVIPControl_ClearS5Auth
FBroVIPControl_DeletResponseFiltereChangeData
FBroVIPControl_DeleteDevToolsMessageObserver
FBroVIPControl_DeleteResourceHandlerAllData
FBroVIPControl_DeleteResourceHandlerChangeData
FBroVIPControl_DeleteResponseFilterAllData
FBroVIPControl_DispatchKeyEvent
FBroVIPControl_DispatchMouseEvent
FBroVIPControl_DispatchTouchEvent
FBroVIPControl_EnableWebsocketClientHook
FBroVIPControl_ExecuteDevToolsMethod
FBroVIPControl_GetBrowser
FBroVIPControl_GetBrowserPtr
FBroVIPControl_GetFingerCount
FBroVIPControl_PageCaptureScreenshot
FBroVIPControl_PageGetContextID
FBroVIPControl_RuntimeEnable
FBroVIPControl_RuntimeEvaluate
FBroVIPControl_RuntimeEvaluate_FrameID
FBroVIPControl_SendDevToolsMessage
FBroVIPControl_SetAudioFingerPrint_constant
FBroVIPControl_SetAudioFingerPrint_random
FBroVIPControl_SetCanvasFingerPrint_constant
FBroVIPControl_SetCanvasFingerPrint_random
FBroVIPControl_SetDisableConsoleDebug
FBroVIPControl_SetDisableDebugger
FBroVIPControl_SetEmitTouchEventsForMouse
FBroVIPControl_SetPlugins
FBroVIPControl_SetS5Auth
FBroVIPControl_SetSSLCipher
FBroVIPControl_SetTouchEventEmulationEnabled
FBroVIPControl_SetVirAcceptlanguages
FBroVIPControl_SetVirAppCodeName
FBroVIPControl_SetVirAppName
FBroVIPControl_SetVirAppVersion
FBroVIPControl_SetVirAudioInput
FBroVIPControl_SetVirAudioOutput
FBroVIPControl_SetVirBatteryManagerCharging
FBroVIPControl_SetVirBatteryManagerChargingTime
FBroVIPControl_SetVirBatteryManagerDischargingTime
FBroVIPControl_SetVirBatteryManagerLevel
FBroVIPControl_SetVirCSSFontFingerprint
FBroVIPControl_SetVirCanvas2DFontFingerprint
FBroVIPControl_SetVirCookieEnabled
FBroVIPControl_SetVirDeviceMemory
FBroVIPControl_SetVirDevicePixelRatio
FBroVIPControl_SetVirHardwareConcurrency
FBroVIPControl_SetVirJavaEnabled
FBroVIPControl_SetVirKernel
FBroVIPControl_SetVirLanguages
FBroVIPControl_SetVirLongitudeAndLatitude
FBroVIPControl_SetVirOnLine
FBroVIPControl_SetVirOrientation
FBroVIPControl_SetVirPlatform
FBroVIPControl_SetVirProduct
FBroVIPControl_SetVirProductSub
FBroVIPControl_SetVirRectFingerprint
FBroVIPControl_SetVirScreenHeightAndWidth
FBroVIPControl_SetVirScreenXAndY
FBroVIPControl_SetVirScreenavailHeightAndWidth
FBroVIPControl_SetVirScreencolorDepth
FBroVIPControl_SetVirScreenpixelDepth
FBroVIPControl_SetVirTimeZone
FBroVIPControl_SetVirUserAgent
FBroVIPControl_SetVirVendor
FBroVIPControl_SetVirVendorSub
FBroVIPControl_SetVirVideoInput
FBroVIPControl_SetVirViewport
FBroVIPControl_SetVirWebdriver
FBroVIPControl_SetVirWebglrenderer
FBroVIPControl_SetVirWebglvendor
FBroVIPControl_SetVirWebrtcIP
FBroVIPControl_SetVirisTrusted
FBroVIPControl_SetWebGLFingerPrint_constant
FBroVIPControl_SetWebGLFingerPrint_random
FBroVIPCountControl
FBroVIPGetRealPoint
FBroVIPGlobal_SetS5Auth
FBroVIPNewBountControl
FBroVIPNewClass
FBroVIPRequestContext_EnableExtensionPlus
FBroVIPResourceHandler_AddChangeData
FBroVIPResourceHandler_AddChangeFile
FBroVIPResourceHandler_DeleteAllData
FBroVIPResourceHandler_DeleteChangeData
FBroVIPResponseFilter_AddChangeData
FBroVIPResponseFilter_DeleteAllData
FBroVIPResponseFilter_DeleteChangeData
HookEVIPEvent
""".strip().split('\n')
FUNCS = [f.strip() for f in FUNCS if f.strip()]

# Functions we intercept with hardcoded return values
INTERCEPT = {
    'FBroOnlineLicenseControl_SetKey',            # return 0
    'FBroOnlineLicenseControl_GetError',           # return 0
    'FBroOnlineLicenseControl_GetShowLicenseType', # return 2
    'FBroOnlineLicenseControl_GetShowLicenseStartDate', # 1735689600LL
    'FBroOnlineLicenseControl_GetShowLicenseEndDate',   # 4102444799LL
    'FBroOnlineLicenseControl_GetShowLicenseDevTool',   # return 1
    'FBroOnlineLicenseControl_GetShowLicenseFunction',  # return -1
    'FBroOnlineLicenseControl_GetShowLicenseSysVersion',# return 1
    'FBroBrowser_IsLicenceKey',                   # return TRUE
    'FBroBrowser_SetLicenceKey',                  # stub
    'FBroBrowser_GetMachineCode',                 # return fixed string
}

# Infer return type from function name
def return_type(name):
    if name in ('FBroBrowser_GetExpirationTime', 'FBroBrowser_GetRegistrationTime',
                'FBroOnlineLicenseControl_GetShowLicenseStartDate',
                'FBroOnlineLicenseControl_GetShowLicenseEndDate'):
        return 'long long'
    if name == 'FBroBrowser_GetMachineCode':
        return 'const char*'
    if name == 'FBroBrowser_GetFunctionStr':
        return 'const char*'
    if name == 'FBroBrowser_SetLicenceKey':
        return 'void'
    return 'int'

def stdcall_suffix(name):
    rt = return_type(name)
    if rt == 'long long':
        return '(void)'
    elif rt == 'const char*':
        # MachineCode and GetFunctionStr take no args
        return '(void)'
    elif rt == 'void':
        return '(const char* key)'
    else:
        return '(void)'

# -----------------------------------------------------------------------
# Generate proxy.c
# -----------------------------------------------------------------------

lines = []
lines.append('/* Auto-generated FBrowserVIP.dll proxy — all functions forwarded via table */')
lines.append('/* Compile: cl /nologo /O2 /GS- /MD /LD dll_proxy.c */')
lines.append('')
lines.append('#include <windows.h>')
lines.append('')
lines.append('#pragma comment(lib, "user32.lib")')
lines.append('')
lines.append('/* Function pointer table */')
lines.append('#define TOTAL_EXPORTS %d' % len(FUNCS))
lines.append('FARPROC g_pfn[TOTAL_EXPORTS];')
lines.append('HMODULE g_hOrig;')
lines.append('BOOL g_bInit;')
lines.append('')

# Init function
lines.append('static void init_ptrs(void)')
lines.append('{')
lines.append('    if (g_bInit) return;')
lines.append('    wchar_t path[MAX_PATH];')
lines.append('    GetModuleFileNameW(NULL, path, MAX_PATH);')
lines.append('    wchar_t* bs = wcsrchr(path, L\'\\\\\');')
lines.append('    if (bs) {')
lines.append('        *(bs+1) = L\'\\0\';')
lines.append('        wcscat(path, L"FBrowserVIP_original.dll");')
lines.append('    }')
lines.append('    g_hOrig = LoadLibraryW(path);')
lines.append('    if (!g_hOrig) {')
lines.append('        g_hOrig = LoadLibraryA("FBrowserVIP_original.dll");')
lines.append('    }')
for i, name in enumerate(FUNCS):
    lines.append('    g_pfn[%d] = GetProcAddress(g_hOrig, "%s");' % (i, name))
lines.append('    g_bInit = TRUE;')
lines.append('}')
lines.append('')

# Intercept functions
lines.append('/* ===== Intercepted functions ===== */')
lines.append('')
for name in FUNCS:
    if name not in INTERCEPT:
        continue
    rt = return_type(name)
    args = stdcall_suffix(name)

    if name == 'FBroBrowser_IsLicenceKey':
        lines.append('BOOL __stdcall FBroBrowser_IsLicenceKey(void) { return 1; }')
    elif name == 'FBroBrowser_SetLicenceKey':
        lines.append('void __stdcall FBroBrowser_SetLicenceKey(const char* key) { }')
    elif name == 'FBroBrowser_GetMachineCode':
        lines.append('const char* __stdcall FBroBrowser_GetMachineCode(void) { return "S17JNTM-FIXED-MACHINE-CODE-00001"; }')
    elif name == 'FBroOnlineLicenseControl_SetKey':
        lines.append('int __stdcall FBroOnlineLicenseControl_SetKey(const char* key) { return 0; }')
    elif name == 'FBroOnlineLicenseControl_GetError':
        lines.append('int __stdcall FBroOnlineLicenseControl_GetError(void) { return 0; }')
    elif name == 'FBroOnlineLicenseControl_GetShowLicenseType':
        lines.append('int __stdcall FBroOnlineLicenseControl_GetShowLicenseType(void) { return 2; }')
    elif name == 'FBroOnlineLicenseControl_GetShowLicenseStartDate':
        lines.append('long long __stdcall FBroOnlineLicenseControl_GetShowLicenseStartDate(void) { return 1735689600LL; }')
    elif name == 'FBroOnlineLicenseControl_GetShowLicenseEndDate':
        lines.append('long long __stdcall FBroOnlineLicenseControl_GetShowLicenseEndDate(void) { return 4102444799LL; }')
    elif name == 'FBroOnlineLicenseControl_GetShowLicenseDevTool':
        lines.append('int __stdcall FBroOnlineLicenseControl_GetShowLicenseDevTool(void) { return 1; }')
    elif name == 'FBroOnlineLicenseControl_GetShowLicenseFunction':
        lines.append('int __stdcall FBroOnlineLicenseControl_GetShowLicenseFunction(void) { return -1; }')
    elif name == 'FBroOnlineLicenseControl_GetShowLicenseSysVersion':
        lines.append('int __stdcall FBroOnlineLicenseControl_GetShowLicenseSysVersion(void) { return 1; }')
    lines.append('')

# Forwarding functions — using tail-call via function table
lines.append('/* ===== Forwarding functions ===== */')
lines.append('')
for i, name in enumerate(FUNCS):
    if name in INTERCEPT:
        continue
    rt = return_type(name)
    args = stdcall_suffix(name)

    if rt == 'void':
        lines.append('void __stdcall %s%s { init_ptrs(); ((void(__stdcall*)())g_pfn[%d])(); }' % (name, args, i))
    else:
        lines.append('%s __stdcall %s%s { init_ptrs(); return ((%s(__stdcall*)())g_pfn[%d])(); }' % (rt, name, args, rt, i))
    lines.append('')

# DllMain
lines.append('BOOL WINAPI DllMain(HINSTANCE h, DWORD r, LPVOID rv)')
lines.append('{')
lines.append('    if (r == DLL_PROCESS_ATTACH) DisableThreadLibraryCalls(h);')
lines.append('    return TRUE;')
lines.append('}')
lines.append('')

# .def file content
lines.append('/*')
lines.append(' * .def file contents (save as dll_proxy.def):')
lines.append(' * EXPORTS')
for name in FUNCS:
    lines.append(' *   %s' % name)
lines.append(' */')

proxy_c = '\n'.join(lines)

# -----------------------------------------------------------------------
# Generate .def
# -----------------------------------------------------------------------
def_lines = ['EXPORTS']
for name in FUNCS:
    def_lines.append('  %s' % name)

def_content = '\r\n'.join(def_lines)

# -----------------------------------------------------------------------
# Write files
# -----------------------------------------------------------------------
import os
out_dir = os.path.dirname(os.path.abspath(__file__))

with open(os.path.join(out_dir, 'dll_proxy.c'), 'w') as f:
    f.write(proxy_c)

with open(os.path.join(out_dir, 'dll_proxy.def'), 'w') as f:
    f.write(def_content)

print('=== Generated ===')
print(f'  dll_proxy.c: {len(FUNCS)} exports, {len(INTERCEPT)} intercepted, {len(FUNCS)-len(INTERCEPT)} forwarded')
print(f'  dll_proxy.def: {len(FUNCS)} exports listed')
print()
print('Build:')
print(f'  cd {out_dir}')
print('  cl /nologo /O2 /GS- /MD /LD dll_proxy.c /link /DEF:dll_proxy.def')
print()
print('Deploy:')
print('  copy /Y ..\\CEFlib\\FBrowserVIP.dll ..\\CEFlib\\FBrowserVIP_original.dll')
print('  copy /Y dll_proxy.dll ..\\CEFlib\\FBrowserVIP.dll')

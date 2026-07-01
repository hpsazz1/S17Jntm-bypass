/*
 * FBrowserVIP.dll Proxy DLL
 * Replace original FBrowserVIP.dll, intercept license API return values
 * Non-license functions forwarded via #pragma comment(linker, "/export:Foo=Original.Foo")
 *
 * Build (VS Developer Command Prompt x86):
 *   cl /nologo /O2 /GS- /MD /LD dll_proxy.c /link /DEF:dll_proxy.def
 *
 * Deploy:
 *   1. backup FBrowserVIP.dll -> FBrowserVIP_original.dll
 *   2. rename dll_proxy.dll -> FBrowserVIP.dll in CEFlib/
 *   3. run mYjJYFSJwydN.exe
 */

#include <windows.h>
#include <stdio.h>

#pragma comment(lib, "user32.lib")

#pragma comment(linker, "/EXPORT:FBroBrowser_GetExpirationTime=FBrowserVIP_original.FBroBrowser_GetExpirationTime")
#pragma comment(linker, "/EXPORT:FBroBrowser_GetFunctionStr=FBrowserVIP_original.FBroBrowser_GetFunctionStr")
#pragma comment(linker, "/EXPORT:FBroBrowser_GetRegistrationTime=FBrowserVIP_original.FBroBrowser_GetRegistrationTime")
#pragma comment(linker, "/EXPORT:FBroBrowser_GetVIPControl=FBrowserVIP_original.FBroBrowser_GetVIPControl")
#pragma comment(linker, "/EXPORT:FBroBrowser_GetVersionStr=FBrowserVIP_original.FBroBrowser_GetVersionStr")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_disable=FBrowserVIP_original.FBroDevToolsDOM_disable")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_discardSearchResults=FBrowserVIP_original.FBroDevToolsDOM_discardSearchResults")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_enable=FBrowserVIP_original.FBroDevToolsDOM_enable")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_focusElement=FBrowserVIP_original.FBroDevToolsDOM_focusElement")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_getAttributes=FBrowserVIP_original.FBroDevToolsDOM_getAttributes")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_getContainerForNode=FBrowserVIP_original.FBroDevToolsDOM_getContainerForNode")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_getDocument=FBrowserVIP_original.FBroDevToolsDOM_getDocument")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_getOuterHTML=FBrowserVIP_original.FBroDevToolsDOM_getOuterHTML")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_getSearchResults=FBrowserVIP_original.FBroDevToolsDOM_getSearchResults")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_performSearch=FBrowserVIP_original.FBroDevToolsDOM_performSearch")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_querySelector=FBrowserVIP_original.FBroDevToolsDOM_querySelector")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_querySelectorAll=FBrowserVIP_original.FBroDevToolsDOM_querySelectorAll")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_removeAttribute=FBrowserVIP_original.FBroDevToolsDOM_removeAttribute")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_removeNode=FBrowserVIP_original.FBroDevToolsDOM_removeNode")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_setAttributeValue=FBrowserVIP_original.FBroDevToolsDOM_setAttributeValue")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_setAttributesAsText=FBrowserVIP_original.FBroDevToolsDOM_setAttributesAsText")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_setNodeName=FBrowserVIP_original.FBroDevToolsDOM_setNodeName")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_setNodeValue=FBrowserVIP_original.FBroDevToolsDOM_setNodeValue")
#pragma comment(linker, "/EXPORT:FBroDevToolsDOM_setOuterHTML=FBrowserVIP_original.FBroDevToolsDOM_setOuterHTML")
#pragma comment(linker, "/EXPORT:FBroVIPBountControl=FBrowserVIP_original.FBroVIPBountControl")
#pragma comment(linker, "/EXPORT:FBroVIPControl_AddDevToolsMessageObserver=FBrowserVIP_original.FBroVIPControl_AddDevToolsMessageObserver")
#pragma comment(linker, "/EXPORT:FBroVIPControl_AddResourceHandlerChangeData=FBrowserVIP_original.FBroVIPControl_AddResourceHandlerChangeData")
#pragma comment(linker, "/EXPORT:FBroVIPControl_AddResourceHandlerChangeFile=FBrowserVIP_original.FBroVIPControl_AddResourceHandlerChangeFile")
#pragma comment(linker, "/EXPORT:FBroVIPControl_AddResponseFilterChangeData=FBrowserVIP_original.FBroVIPControl_AddResponseFilterChangeData")
#pragma comment(linker, "/EXPORT:FBroVIPControl_ClearAllData=FBrowserVIP_original.FBroVIPControl_ClearAllData")
#pragma comment(linker, "/EXPORT:FBroVIPControl_ClearFingerCount=FBrowserVIP_original.FBroVIPControl_ClearFingerCount")
#pragma comment(linker, "/EXPORT:FBroVIPControl_ClearS5Auth=FBrowserVIP_original.FBroVIPControl_ClearS5Auth")
#pragma comment(linker, "/EXPORT:FBroVIPControl_DeletResponseFiltereChangeData=FBrowserVIP_original.FBroVIPControl_DeletResponseFiltereChangeData")
#pragma comment(linker, "/EXPORT:FBroVIPControl_DeleteDevToolsMessageObserver=FBrowserVIP_original.FBroVIPControl_DeleteDevToolsMessageObserver")
#pragma comment(linker, "/EXPORT:FBroVIPControl_DeleteResourceHandlerAllData=FBrowserVIP_original.FBroVIPControl_DeleteResourceHandlerAllData")
#pragma comment(linker, "/EXPORT:FBroVIPControl_DeleteResourceHandlerChangeData=FBrowserVIP_original.FBroVIPControl_DeleteResourceHandlerChangeData")
#pragma comment(linker, "/EXPORT:FBroVIPControl_DeleteResponseFilterAllData=FBrowserVIP_original.FBroVIPControl_DeleteResponseFilterAllData")
#pragma comment(linker, "/EXPORT:FBroVIPControl_DispatchKeyEvent=FBrowserVIP_original.FBroVIPControl_DispatchKeyEvent")
#pragma comment(linker, "/EXPORT:FBroVIPControl_DispatchMouseEvent=FBrowserVIP_original.FBroVIPControl_DispatchMouseEvent")
#pragma comment(linker, "/EXPORT:FBroVIPControl_DispatchTouchEvent=FBrowserVIP_original.FBroVIPControl_DispatchTouchEvent")
#pragma comment(linker, "/EXPORT:FBroVIPControl_EnableWebsocketClientHook=FBrowserVIP_original.FBroVIPControl_EnableWebsocketClientHook")
#pragma comment(linker, "/EXPORT:FBroVIPControl_ExecuteDevToolsMethod=FBrowserVIP_original.FBroVIPControl_ExecuteDevToolsMethod")
#pragma comment(linker, "/EXPORT:FBroVIPControl_GetBrowser=FBrowserVIP_original.FBroVIPControl_GetBrowser")
#pragma comment(linker, "/EXPORT:FBroVIPControl_GetBrowserPtr=FBrowserVIP_original.FBroVIPControl_GetBrowserPtr")
#pragma comment(linker, "/EXPORT:FBroVIPControl_GetFingerCount=FBrowserVIP_original.FBroVIPControl_GetFingerCount")
#pragma comment(linker, "/EXPORT:FBroVIPControl_PageCaptureScreenshot=FBrowserVIP_original.FBroVIPControl_PageCaptureScreenshot")
#pragma comment(linker, "/EXPORT:FBroVIPControl_PageGetContextID=FBrowserVIP_original.FBroVIPControl_PageGetContextID")
#pragma comment(linker, "/EXPORT:FBroVIPControl_RuntimeEnable=FBrowserVIP_original.FBroVIPControl_RuntimeEnable")
#pragma comment(linker, "/EXPORT:FBroVIPControl_RuntimeEvaluate=FBrowserVIP_original.FBroVIPControl_RuntimeEvaluate")
#pragma comment(linker, "/EXPORT:FBroVIPControl_RuntimeEvaluate_FrameID=FBrowserVIP_original.FBroVIPControl_RuntimeEvaluate_FrameID")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SendDevToolsMessage=FBrowserVIP_original.FBroVIPControl_SendDevToolsMessage")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetAudioFingerPrint_constant=FBrowserVIP_original.FBroVIPControl_SetAudioFingerPrint_constant")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetAudioFingerPrint_random=FBrowserVIP_original.FBroVIPControl_SetAudioFingerPrint_random")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetCanvasFingerPrint_constant=FBrowserVIP_original.FBroVIPControl_SetCanvasFingerPrint_constant")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetCanvasFingerPrint_random=FBrowserVIP_original.FBroVIPControl_SetCanvasFingerPrint_random")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetDisableConsoleDebug=FBrowserVIP_original.FBroVIPControl_SetDisableConsoleDebug")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetDisableDebugger=FBrowserVIP_original.FBroVIPControl_SetDisableDebugger")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetEmitTouchEventsForMouse=FBrowserVIP_original.FBroVIPControl_SetEmitTouchEventsForMouse")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetPlugins=FBrowserVIP_original.FBroVIPControl_SetPlugins")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetS5Auth=FBrowserVIP_original.FBroVIPControl_SetS5Auth")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetSSLCipher=FBrowserVIP_original.FBroVIPControl_SetSSLCipher")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetTouchEventEmulationEnabled=FBrowserVIP_original.FBroVIPControl_SetTouchEventEmulationEnabled")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirAcceptlanguages=FBrowserVIP_original.FBroVIPControl_SetVirAcceptlanguages")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirAppCodeName=FBrowserVIP_original.FBroVIPControl_SetVirAppCodeName")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirAppName=FBrowserVIP_original.FBroVIPControl_SetVirAppName")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirAppVersion=FBrowserVIP_original.FBroVIPControl_SetVirAppVersion")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirAudioInput=FBrowserVIP_original.FBroVIPControl_SetVirAudioInput")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirAudioOutput=FBrowserVIP_original.FBroVIPControl_SetVirAudioOutput")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirBatteryManagerCharging=FBrowserVIP_original.FBroVIPControl_SetVirBatteryManagerCharging")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirBatteryManagerChargingTime=FBrowserVIP_original.FBroVIPControl_SetVirBatteryManagerChargingTime")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirBatteryManagerDischargingTime=FBrowserVIP_original.FBroVIPControl_SetVirBatteryManagerDischargingTime")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirBatteryManagerLevel=FBrowserVIP_original.FBroVIPControl_SetVirBatteryManagerLevel")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirCSSFontFingerprint=FBrowserVIP_original.FBroVIPControl_SetVirCSSFontFingerprint")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirCanvas2DFontFingerprint=FBrowserVIP_original.FBroVIPControl_SetVirCanvas2DFontFingerprint")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirCookieEnabled=FBrowserVIP_original.FBroVIPControl_SetVirCookieEnabled")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirDeviceMemory=FBrowserVIP_original.FBroVIPControl_SetVirDeviceMemory")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirDevicePixelRatio=FBrowserVIP_original.FBroVIPControl_SetVirDevicePixelRatio")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirHardwareConcurrency=FBrowserVIP_original.FBroVIPControl_SetVirHardwareConcurrency")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirJavaEnabled=FBrowserVIP_original.FBroVIPControl_SetVirJavaEnabled")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirKernel=FBrowserVIP_original.FBroVIPControl_SetVirKernel")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirLanguages=FBrowserVIP_original.FBroVIPControl_SetVirLanguages")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirLongitudeAndLatitude=FBrowserVIP_original.FBroVIPControl_SetVirLongitudeAndLatitude")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirOnLine=FBrowserVIP_original.FBroVIPControl_SetVirOnLine")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirOrientation=FBrowserVIP_original.FBroVIPControl_SetVirOrientation")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirPlatform=FBrowserVIP_original.FBroVIPControl_SetVirPlatform")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirProduct=FBrowserVIP_original.FBroVIPControl_SetVirProduct")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirProductSub=FBrowserVIP_original.FBroVIPControl_SetVirProductSub")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirRectFingerprint=FBrowserVIP_original.FBroVIPControl_SetVirRectFingerprint")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirScreenHeightAndWidth=FBrowserVIP_original.FBroVIPControl_SetVirScreenHeightAndWidth")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirScreenXAndY=FBrowserVIP_original.FBroVIPControl_SetVirScreenXAndY")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirScreenavailHeightAndWidth=FBrowserVIP_original.FBroVIPControl_SetVirScreenavailHeightAndWidth")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirScreencolorDepth=FBrowserVIP_original.FBroVIPControl_SetVirScreencolorDepth")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirScreenpixelDepth=FBrowserVIP_original.FBroVIPControl_SetVirScreenpixelDepth")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirTimeZone=FBrowserVIP_original.FBroVIPControl_SetVirTimeZone")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirUserAgent=FBrowserVIP_original.FBroVIPControl_SetVirUserAgent")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirVendor=FBrowserVIP_original.FBroVIPControl_SetVirVendor")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirVendorSub=FBrowserVIP_original.FBroVIPControl_SetVirVendorSub")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirVideoInput=FBrowserVIP_original.FBroVIPControl_SetVirVideoInput")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirViewport=FBrowserVIP_original.FBroVIPControl_SetVirViewport")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirWebdriver=FBrowserVIP_original.FBroVIPControl_SetVirWebdriver")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirWebglrenderer=FBrowserVIP_original.FBroVIPControl_SetVirWebglrenderer")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirWebglvendor=FBrowserVIP_original.FBroVIPControl_SetVirWebglvendor")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirWebrtcIP=FBrowserVIP_original.FBroVIPControl_SetVirWebrtcIP")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetVirisTrusted=FBrowserVIP_original.FBroVIPControl_SetVirisTrusted")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetWebGLFingerPrint_constant=FBrowserVIP_original.FBroVIPControl_SetWebGLFingerPrint_constant")
#pragma comment(linker, "/EXPORT:FBroVIPControl_SetWebGLFingerPrint_random=FBrowserVIP_original.FBroVIPControl_SetWebGLFingerPrint_random")
#pragma comment(linker, "/EXPORT:FBroVIPCountControl=FBrowserVIP_original.FBroVIPCountControl")
#pragma comment(linker, "/EXPORT:FBroVIPGetRealPoint=FBrowserVIP_original.FBroVIPGetRealPoint")
#pragma comment(linker, "/EXPORT:FBroVIPGlobal_SetS5Auth=FBrowserVIP_original.FBroVIPGlobal_SetS5Auth")
#pragma comment(linker, "/EXPORT:FBroVIPNewBountControl=FBrowserVIP_original.FBroVIPNewBountControl")
#pragma comment(linker, "/EXPORT:FBroVIPNewClass=FBrowserVIP_original.FBroVIPNewClass")
#pragma comment(linker, "/EXPORT:FBroVIPRequestContext_EnableExtensionPlus=FBrowserVIP_original.FBroVIPRequestContext_EnableExtensionPlus")
#pragma comment(linker, "/EXPORT:FBroVIPResourceHandler_AddChangeData=FBrowserVIP_original.FBroVIPResourceHandler_AddChangeData")
#pragma comment(linker, "/EXPORT:FBroVIPResourceHandler_AddChangeFile=FBrowserVIP_original.FBroVIPResourceHandler_AddChangeFile")
#pragma comment(linker, "/EXPORT:FBroVIPResourceHandler_DeleteAllData=FBrowserVIP_original.FBroVIPResourceHandler_DeleteAllData")
#pragma comment(linker, "/EXPORT:FBroVIPResourceHandler_DeleteChangeData=FBrowserVIP_original.FBroVIPResourceHandler_DeleteChangeData")
#pragma comment(linker, "/EXPORT:FBroVIPResponseFilter_AddChangeData=FBrowserVIP_original.FBroVIPResponseFilter_AddChangeData")
#pragma comment(linker, "/EXPORT:FBroVIPResponseFilter_DeleteAllData=FBrowserVIP_original.FBroVIPResponseFilter_DeleteAllData")
#pragma comment(linker, "/EXPORT:FBroVIPResponseFilter_DeleteChangeData=FBrowserVIP_original.FBroVIPResponseFilter_DeleteChangeData")
#pragma comment(linker, "/EXPORT:HookEVIPEvent=FBrowserVIP_original.HookEVIPEvent")


HMODULE g_hOriginal = NULL;
BOOL g_bDebug = TRUE;


void dbg(const char* fmt, ...)
{
    if (!g_bDebug) return;
    char buf[512];
    va_list args;
    va_start(args, fmt);
    wvsprintfA(buf, fmt, args);
    va_end(args);
    OutputDebugStringA("[FBProxy] ");
    OutputDebugStringA(buf);
    OutputDebugStringA("\n");
}


BOOL WINAPI DllMain(HINSTANCE hinst, DWORD reason, LPVOID reserved)
{
    if (reason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hinst);
        dbg("DllMain: loading FBrowserVIP_original.dll...");
        g_hOriginal = LoadLibraryA("FBrowserVIP_original.dll");
        if (g_hOriginal)
            dbg("DllMain: original DLL loaded at 0x%08X", (UINT)g_hOriginal);
        else
            dbg("DllMain: FAILED to load original DLL! err=%d", GetLastError());
    }
    return TRUE;
}


BOOL __stdcall FBroBrowser_IsLicenceKey(void)
{
    dbg("FBroBrowser_IsLicenceKey -> returning TRUE");
    return TRUE;
}


void __stdcall FBroBrowser_SetLicenceKey(const char* key)
{
    if (key)
        dbg("FBroBrowser_SetLicenceKey(\"%s\") -> stub (no-op)", key);
    else
        dbg("FBroBrowser_SetLicenceKey(NULL) -> stub (no-op)");
}


const char* __stdcall FBroBrowser_GetMachineCode(void)
{
    dbg("FBroBrowser_GetMachineCode -> returning fixed code");
    return "S17JNTM-FIXED-MACHINE-CODE-00001";
}


int __stdcall FBroOnlineLicenseControl_SetKey(const char* key)
{
    if (key)
        dbg("FBroOnlineLicenseControl_SetKey(\"%s\") -> accepted", key);
    else
        dbg("FBroOnlineLicenseControl_SetKey(NULL) -> accepted");
    return 0;
}


int __stdcall FBroOnlineLicenseControl_GetError(void)
{
    dbg("FBroOnlineLicenseControl_GetError -> returning 0 (no error)");
    return 0;
}


int __stdcall FBroOnlineLicenseControl_GetShowLicenseType(void)
{
    dbg("FBroOnlineLicenseControl_GetShowLicenseType -> returning 2 (full)");
    return 2;
}


long long __stdcall FBroOnlineLicenseControl_GetShowLicenseStartDate(void)
{
    dbg("FBroOnlineLicenseControl_GetShowLicenseStartDate -> returning 2025-01-01");
    return 1735689600LL;
}


long long __stdcall FBroOnlineLicenseControl_GetShowLicenseEndDate(void)
{
    dbg("FBroOnlineLicenseControl_GetShowLicenseEndDate -> returning 2099-12-31");
    return 4102444799LL;
}


int __stdcall FBroOnlineLicenseControl_GetShowLicenseDevTool(void)
{
    dbg("FBroOnlineLicenseControl_GetShowLicenseDevTool -> returning 1 (enabled)");
    return 1;
}


int __stdcall FBroOnlineLicenseControl_GetShowLicenseFunction(void)
{
    dbg("FBroOnlineLicenseControl_GetShowLicenseFunction -> returning 0xFFFFFFFF (all)");
    return 0xFFFFFFFF;
}


int __stdcall FBroOnlineLicenseControl_GetShowLicenseSysVersion(void)
{
    dbg("FBroOnlineLicenseControl_GetShowLicenseSysVersion -> returning 1");
    return 1;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
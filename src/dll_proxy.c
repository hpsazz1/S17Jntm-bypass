/* Auto-generated FBrowserVIP.dll proxy — all functions forwarded via table */
/* Compile: cl /nologo /O2 /GS- /MD /LD dll_proxy.c */

#include <windows.h>

#pragma comment(lib, "user32.lib")

/* Function pointer table */
#define TOTAL_EXPORTS 131
FARPROC g_pfn[TOTAL_EXPORTS];
HMODULE g_hOrig;
BOOL g_bInit;

static void init_ptrs(void)
{
    if (g_bInit) return;
    wchar_t path[MAX_PATH];
    GetModuleFileNameW(NULL, path, MAX_PATH);
    wchar_t* bs = wcsrchr(path, L'\\');
    if (bs) {
        *(bs+1) = L'\0';
        wcscat(path, L"FBrowserVIP_original.dll");
    }
    g_hOrig = LoadLibraryW(path);
    if (!g_hOrig) {
        g_hOrig = LoadLibraryA("FBrowserVIP_original.dll");
    }
    g_pfn[0] = GetProcAddress(g_hOrig, "FBroBrowser_GetExpirationTime");
    g_pfn[1] = GetProcAddress(g_hOrig, "FBroBrowser_GetFunctionStr");
    g_pfn[2] = GetProcAddress(g_hOrig, "FBroBrowser_GetMachineCode");
    g_pfn[3] = GetProcAddress(g_hOrig, "FBroBrowser_GetRegistrationTime");
    g_pfn[4] = GetProcAddress(g_hOrig, "FBroBrowser_GetVIPControl");
    g_pfn[5] = GetProcAddress(g_hOrig, "FBroBrowser_GetVersionStr");
    g_pfn[6] = GetProcAddress(g_hOrig, "FBroBrowser_IsLicenceKey");
    g_pfn[7] = GetProcAddress(g_hOrig, "FBroBrowser_SetLicenceKey");
    g_pfn[8] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_disable");
    g_pfn[9] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_discardSearchResults");
    g_pfn[10] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_enable");
    g_pfn[11] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_focusElement");
    g_pfn[12] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_getAttributes");
    g_pfn[13] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_getContainerForNode");
    g_pfn[14] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_getDocument");
    g_pfn[15] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_getOuterHTML");
    g_pfn[16] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_getSearchResults");
    g_pfn[17] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_performSearch");
    g_pfn[18] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_querySelector");
    g_pfn[19] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_querySelectorAll");
    g_pfn[20] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_removeAttribute");
    g_pfn[21] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_removeNode");
    g_pfn[22] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_setAttributeValue");
    g_pfn[23] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_setAttributesAsText");
    g_pfn[24] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_setNodeName");
    g_pfn[25] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_setNodeValue");
    g_pfn[26] = GetProcAddress(g_hOrig, "FBroDevToolsDOM_setOuterHTML");
    g_pfn[27] = GetProcAddress(g_hOrig, "FBroOnlineLicenseControl_GetError");
    g_pfn[28] = GetProcAddress(g_hOrig, "FBroOnlineLicenseControl_GetShowLicenseDevTool");
    g_pfn[29] = GetProcAddress(g_hOrig, "FBroOnlineLicenseControl_GetShowLicenseEndDate");
    g_pfn[30] = GetProcAddress(g_hOrig, "FBroOnlineLicenseControl_GetShowLicenseFunction");
    g_pfn[31] = GetProcAddress(g_hOrig, "FBroOnlineLicenseControl_GetShowLicenseStartDate");
    g_pfn[32] = GetProcAddress(g_hOrig, "FBroOnlineLicenseControl_GetShowLicenseSysVersion");
    g_pfn[33] = GetProcAddress(g_hOrig, "FBroOnlineLicenseControl_GetShowLicenseType");
    g_pfn[34] = GetProcAddress(g_hOrig, "FBroOnlineLicenseControl_SetKey");
    g_pfn[35] = GetProcAddress(g_hOrig, "FBroVIPBountControl");
    g_pfn[36] = GetProcAddress(g_hOrig, "FBroVIPControl_AddDevToolsMessageObserver");
    g_pfn[37] = GetProcAddress(g_hOrig, "FBroVIPControl_AddResourceHandlerChangeData");
    g_pfn[38] = GetProcAddress(g_hOrig, "FBroVIPControl_AddResourceHandlerChangeFile");
    g_pfn[39] = GetProcAddress(g_hOrig, "FBroVIPControl_AddResponseFilterChangeData");
    g_pfn[40] = GetProcAddress(g_hOrig, "FBroVIPControl_ClearAllData");
    g_pfn[41] = GetProcAddress(g_hOrig, "FBroVIPControl_ClearFingerCount");
    g_pfn[42] = GetProcAddress(g_hOrig, "FBroVIPControl_ClearS5Auth");
    g_pfn[43] = GetProcAddress(g_hOrig, "FBroVIPControl_DeletResponseFiltereChangeData");
    g_pfn[44] = GetProcAddress(g_hOrig, "FBroVIPControl_DeleteDevToolsMessageObserver");
    g_pfn[45] = GetProcAddress(g_hOrig, "FBroVIPControl_DeleteResourceHandlerAllData");
    g_pfn[46] = GetProcAddress(g_hOrig, "FBroVIPControl_DeleteResourceHandlerChangeData");
    g_pfn[47] = GetProcAddress(g_hOrig, "FBroVIPControl_DeleteResponseFilterAllData");
    g_pfn[48] = GetProcAddress(g_hOrig, "FBroVIPControl_DispatchKeyEvent");
    g_pfn[49] = GetProcAddress(g_hOrig, "FBroVIPControl_DispatchMouseEvent");
    g_pfn[50] = GetProcAddress(g_hOrig, "FBroVIPControl_DispatchTouchEvent");
    g_pfn[51] = GetProcAddress(g_hOrig, "FBroVIPControl_EnableWebsocketClientHook");
    g_pfn[52] = GetProcAddress(g_hOrig, "FBroVIPControl_ExecuteDevToolsMethod");
    g_pfn[53] = GetProcAddress(g_hOrig, "FBroVIPControl_GetBrowser");
    g_pfn[54] = GetProcAddress(g_hOrig, "FBroVIPControl_GetBrowserPtr");
    g_pfn[55] = GetProcAddress(g_hOrig, "FBroVIPControl_GetFingerCount");
    g_pfn[56] = GetProcAddress(g_hOrig, "FBroVIPControl_PageCaptureScreenshot");
    g_pfn[57] = GetProcAddress(g_hOrig, "FBroVIPControl_PageGetContextID");
    g_pfn[58] = GetProcAddress(g_hOrig, "FBroVIPControl_RuntimeEnable");
    g_pfn[59] = GetProcAddress(g_hOrig, "FBroVIPControl_RuntimeEvaluate");
    g_pfn[60] = GetProcAddress(g_hOrig, "FBroVIPControl_RuntimeEvaluate_FrameID");
    g_pfn[61] = GetProcAddress(g_hOrig, "FBroVIPControl_SendDevToolsMessage");
    g_pfn[62] = GetProcAddress(g_hOrig, "FBroVIPControl_SetAudioFingerPrint_constant");
    g_pfn[63] = GetProcAddress(g_hOrig, "FBroVIPControl_SetAudioFingerPrint_random");
    g_pfn[64] = GetProcAddress(g_hOrig, "FBroVIPControl_SetCanvasFingerPrint_constant");
    g_pfn[65] = GetProcAddress(g_hOrig, "FBroVIPControl_SetCanvasFingerPrint_random");
    g_pfn[66] = GetProcAddress(g_hOrig, "FBroVIPControl_SetDisableConsoleDebug");
    g_pfn[67] = GetProcAddress(g_hOrig, "FBroVIPControl_SetDisableDebugger");
    g_pfn[68] = GetProcAddress(g_hOrig, "FBroVIPControl_SetEmitTouchEventsForMouse");
    g_pfn[69] = GetProcAddress(g_hOrig, "FBroVIPControl_SetPlugins");
    g_pfn[70] = GetProcAddress(g_hOrig, "FBroVIPControl_SetS5Auth");
    g_pfn[71] = GetProcAddress(g_hOrig, "FBroVIPControl_SetSSLCipher");
    g_pfn[72] = GetProcAddress(g_hOrig, "FBroVIPControl_SetTouchEventEmulationEnabled");
    g_pfn[73] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirAcceptlanguages");
    g_pfn[74] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirAppCodeName");
    g_pfn[75] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirAppName");
    g_pfn[76] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirAppVersion");
    g_pfn[77] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirAudioInput");
    g_pfn[78] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirAudioOutput");
    g_pfn[79] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirBatteryManagerCharging");
    g_pfn[80] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirBatteryManagerChargingTime");
    g_pfn[81] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirBatteryManagerDischargingTime");
    g_pfn[82] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirBatteryManagerLevel");
    g_pfn[83] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirCSSFontFingerprint");
    g_pfn[84] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirCanvas2DFontFingerprint");
    g_pfn[85] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirCookieEnabled");
    g_pfn[86] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirDeviceMemory");
    g_pfn[87] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirDevicePixelRatio");
    g_pfn[88] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirHardwareConcurrency");
    g_pfn[89] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirJavaEnabled");
    g_pfn[90] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirKernel");
    g_pfn[91] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirLanguages");
    g_pfn[92] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirLongitudeAndLatitude");
    g_pfn[93] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirOnLine");
    g_pfn[94] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirOrientation");
    g_pfn[95] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirPlatform");
    g_pfn[96] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirProduct");
    g_pfn[97] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirProductSub");
    g_pfn[98] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirRectFingerprint");
    g_pfn[99] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirScreenHeightAndWidth");
    g_pfn[100] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirScreenXAndY");
    g_pfn[101] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirScreenavailHeightAndWidth");
    g_pfn[102] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirScreencolorDepth");
    g_pfn[103] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirScreenpixelDepth");
    g_pfn[104] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirTimeZone");
    g_pfn[105] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirUserAgent");
    g_pfn[106] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirVendor");
    g_pfn[107] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirVendorSub");
    g_pfn[108] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirVideoInput");
    g_pfn[109] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirViewport");
    g_pfn[110] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirWebdriver");
    g_pfn[111] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirWebglrenderer");
    g_pfn[112] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirWebglvendor");
    g_pfn[113] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirWebrtcIP");
    g_pfn[114] = GetProcAddress(g_hOrig, "FBroVIPControl_SetVirisTrusted");
    g_pfn[115] = GetProcAddress(g_hOrig, "FBroVIPControl_SetWebGLFingerPrint_constant");
    g_pfn[116] = GetProcAddress(g_hOrig, "FBroVIPControl_SetWebGLFingerPrint_random");
    g_pfn[117] = GetProcAddress(g_hOrig, "FBroVIPCountControl");
    g_pfn[118] = GetProcAddress(g_hOrig, "FBroVIPGetRealPoint");
    g_pfn[119] = GetProcAddress(g_hOrig, "FBroVIPGlobal_SetS5Auth");
    g_pfn[120] = GetProcAddress(g_hOrig, "FBroVIPNewBountControl");
    g_pfn[121] = GetProcAddress(g_hOrig, "FBroVIPNewClass");
    g_pfn[122] = GetProcAddress(g_hOrig, "FBroVIPRequestContext_EnableExtensionPlus");
    g_pfn[123] = GetProcAddress(g_hOrig, "FBroVIPResourceHandler_AddChangeData");
    g_pfn[124] = GetProcAddress(g_hOrig, "FBroVIPResourceHandler_AddChangeFile");
    g_pfn[125] = GetProcAddress(g_hOrig, "FBroVIPResourceHandler_DeleteAllData");
    g_pfn[126] = GetProcAddress(g_hOrig, "FBroVIPResourceHandler_DeleteChangeData");
    g_pfn[127] = GetProcAddress(g_hOrig, "FBroVIPResponseFilter_AddChangeData");
    g_pfn[128] = GetProcAddress(g_hOrig, "FBroVIPResponseFilter_DeleteAllData");
    g_pfn[129] = GetProcAddress(g_hOrig, "FBroVIPResponseFilter_DeleteChangeData");
    g_pfn[130] = GetProcAddress(g_hOrig, "HookEVIPEvent");
    g_bInit = TRUE;
}

/* ===== Intercepted functions ===== */

const char* __stdcall FBroBrowser_GetMachineCode(void) { return "S17JNTM-FIXED-MACHINE-CODE-00001"; }

BOOL __stdcall FBroBrowser_IsLicenceKey(void) { return 1; }

void __stdcall FBroBrowser_SetLicenceKey(const char* key) { }

int __stdcall FBroOnlineLicenseControl_GetError(void) { return 0; }

int __stdcall FBroOnlineLicenseControl_GetShowLicenseDevTool(void) { return 1; }

long long __stdcall FBroOnlineLicenseControl_GetShowLicenseEndDate(void) { return 4102444799LL; }

int __stdcall FBroOnlineLicenseControl_GetShowLicenseFunction(void) { return -1; }

long long __stdcall FBroOnlineLicenseControl_GetShowLicenseStartDate(void) { return 1735689600LL; }

int __stdcall FBroOnlineLicenseControl_GetShowLicenseSysVersion(void) { return 1; }

int __stdcall FBroOnlineLicenseControl_GetShowLicenseType(void) { return 2; }

int __stdcall FBroOnlineLicenseControl_SetKey(const char* key) { return 0; }

/* ===== Forwarding functions ===== */

long long __stdcall FBroBrowser_GetExpirationTime(void) { init_ptrs(); return ((long long(__stdcall*)())g_pfn[0])(); }

const char* __stdcall FBroBrowser_GetFunctionStr(void) { init_ptrs(); return ((const char*(__stdcall*)())g_pfn[1])(); }

long long __stdcall FBroBrowser_GetRegistrationTime(void) { init_ptrs(); return ((long long(__stdcall*)())g_pfn[3])(); }

int __stdcall FBroBrowser_GetVIPControl(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[4])(); }

int __stdcall FBroBrowser_GetVersionStr(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[5])(); }

int __stdcall FBroDevToolsDOM_disable(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[8])(); }

int __stdcall FBroDevToolsDOM_discardSearchResults(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[9])(); }

int __stdcall FBroDevToolsDOM_enable(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[10])(); }

int __stdcall FBroDevToolsDOM_focusElement(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[11])(); }

int __stdcall FBroDevToolsDOM_getAttributes(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[12])(); }

int __stdcall FBroDevToolsDOM_getContainerForNode(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[13])(); }

int __stdcall FBroDevToolsDOM_getDocument(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[14])(); }

int __stdcall FBroDevToolsDOM_getOuterHTML(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[15])(); }

int __stdcall FBroDevToolsDOM_getSearchResults(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[16])(); }

int __stdcall FBroDevToolsDOM_performSearch(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[17])(); }

int __stdcall FBroDevToolsDOM_querySelector(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[18])(); }

int __stdcall FBroDevToolsDOM_querySelectorAll(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[19])(); }

int __stdcall FBroDevToolsDOM_removeAttribute(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[20])(); }

int __stdcall FBroDevToolsDOM_removeNode(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[21])(); }

int __stdcall FBroDevToolsDOM_setAttributeValue(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[22])(); }

int __stdcall FBroDevToolsDOM_setAttributesAsText(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[23])(); }

int __stdcall FBroDevToolsDOM_setNodeName(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[24])(); }

int __stdcall FBroDevToolsDOM_setNodeValue(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[25])(); }

int __stdcall FBroDevToolsDOM_setOuterHTML(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[26])(); }

int __stdcall FBroVIPBountControl(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[35])(); }

int __stdcall FBroVIPControl_AddDevToolsMessageObserver(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[36])(); }

int __stdcall FBroVIPControl_AddResourceHandlerChangeData(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[37])(); }

int __stdcall FBroVIPControl_AddResourceHandlerChangeFile(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[38])(); }

int __stdcall FBroVIPControl_AddResponseFilterChangeData(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[39])(); }

int __stdcall FBroVIPControl_ClearAllData(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[40])(); }

int __stdcall FBroVIPControl_ClearFingerCount(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[41])(); }

int __stdcall FBroVIPControl_ClearS5Auth(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[42])(); }

int __stdcall FBroVIPControl_DeletResponseFiltereChangeData(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[43])(); }

int __stdcall FBroVIPControl_DeleteDevToolsMessageObserver(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[44])(); }

int __stdcall FBroVIPControl_DeleteResourceHandlerAllData(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[45])(); }

int __stdcall FBroVIPControl_DeleteResourceHandlerChangeData(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[46])(); }

int __stdcall FBroVIPControl_DeleteResponseFilterAllData(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[47])(); }

int __stdcall FBroVIPControl_DispatchKeyEvent(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[48])(); }

int __stdcall FBroVIPControl_DispatchMouseEvent(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[49])(); }

int __stdcall FBroVIPControl_DispatchTouchEvent(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[50])(); }

int __stdcall FBroVIPControl_EnableWebsocketClientHook(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[51])(); }

int __stdcall FBroVIPControl_ExecuteDevToolsMethod(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[52])(); }

int __stdcall FBroVIPControl_GetBrowser(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[53])(); }

int __stdcall FBroVIPControl_GetBrowserPtr(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[54])(); }

int __stdcall FBroVIPControl_GetFingerCount(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[55])(); }

int __stdcall FBroVIPControl_PageCaptureScreenshot(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[56])(); }

int __stdcall FBroVIPControl_PageGetContextID(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[57])(); }

int __stdcall FBroVIPControl_RuntimeEnable(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[58])(); }

int __stdcall FBroVIPControl_RuntimeEvaluate(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[59])(); }

int __stdcall FBroVIPControl_RuntimeEvaluate_FrameID(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[60])(); }

int __stdcall FBroVIPControl_SendDevToolsMessage(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[61])(); }

int __stdcall FBroVIPControl_SetAudioFingerPrint_constant(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[62])(); }

int __stdcall FBroVIPControl_SetAudioFingerPrint_random(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[63])(); }

int __stdcall FBroVIPControl_SetCanvasFingerPrint_constant(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[64])(); }

int __stdcall FBroVIPControl_SetCanvasFingerPrint_random(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[65])(); }

int __stdcall FBroVIPControl_SetDisableConsoleDebug(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[66])(); }

int __stdcall FBroVIPControl_SetDisableDebugger(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[67])(); }

int __stdcall FBroVIPControl_SetEmitTouchEventsForMouse(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[68])(); }

int __stdcall FBroVIPControl_SetPlugins(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[69])(); }

int __stdcall FBroVIPControl_SetS5Auth(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[70])(); }

int __stdcall FBroVIPControl_SetSSLCipher(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[71])(); }

int __stdcall FBroVIPControl_SetTouchEventEmulationEnabled(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[72])(); }

int __stdcall FBroVIPControl_SetVirAcceptlanguages(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[73])(); }

int __stdcall FBroVIPControl_SetVirAppCodeName(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[74])(); }

int __stdcall FBroVIPControl_SetVirAppName(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[75])(); }

int __stdcall FBroVIPControl_SetVirAppVersion(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[76])(); }

int __stdcall FBroVIPControl_SetVirAudioInput(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[77])(); }

int __stdcall FBroVIPControl_SetVirAudioOutput(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[78])(); }

int __stdcall FBroVIPControl_SetVirBatteryManagerCharging(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[79])(); }

int __stdcall FBroVIPControl_SetVirBatteryManagerChargingTime(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[80])(); }

int __stdcall FBroVIPControl_SetVirBatteryManagerDischargingTime(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[81])(); }

int __stdcall FBroVIPControl_SetVirBatteryManagerLevel(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[82])(); }

int __stdcall FBroVIPControl_SetVirCSSFontFingerprint(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[83])(); }

int __stdcall FBroVIPControl_SetVirCanvas2DFontFingerprint(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[84])(); }

int __stdcall FBroVIPControl_SetVirCookieEnabled(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[85])(); }

int __stdcall FBroVIPControl_SetVirDeviceMemory(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[86])(); }

int __stdcall FBroVIPControl_SetVirDevicePixelRatio(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[87])(); }

int __stdcall FBroVIPControl_SetVirHardwareConcurrency(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[88])(); }

int __stdcall FBroVIPControl_SetVirJavaEnabled(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[89])(); }

int __stdcall FBroVIPControl_SetVirKernel(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[90])(); }

int __stdcall FBroVIPControl_SetVirLanguages(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[91])(); }

int __stdcall FBroVIPControl_SetVirLongitudeAndLatitude(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[92])(); }

int __stdcall FBroVIPControl_SetVirOnLine(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[93])(); }

int __stdcall FBroVIPControl_SetVirOrientation(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[94])(); }

int __stdcall FBroVIPControl_SetVirPlatform(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[95])(); }

int __stdcall FBroVIPControl_SetVirProduct(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[96])(); }

int __stdcall FBroVIPControl_SetVirProductSub(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[97])(); }

int __stdcall FBroVIPControl_SetVirRectFingerprint(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[98])(); }

int __stdcall FBroVIPControl_SetVirScreenHeightAndWidth(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[99])(); }

int __stdcall FBroVIPControl_SetVirScreenXAndY(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[100])(); }

int __stdcall FBroVIPControl_SetVirScreenavailHeightAndWidth(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[101])(); }

int __stdcall FBroVIPControl_SetVirScreencolorDepth(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[102])(); }

int __stdcall FBroVIPControl_SetVirScreenpixelDepth(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[103])(); }

int __stdcall FBroVIPControl_SetVirTimeZone(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[104])(); }

int __stdcall FBroVIPControl_SetVirUserAgent(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[105])(); }

int __stdcall FBroVIPControl_SetVirVendor(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[106])(); }

int __stdcall FBroVIPControl_SetVirVendorSub(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[107])(); }

int __stdcall FBroVIPControl_SetVirVideoInput(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[108])(); }

int __stdcall FBroVIPControl_SetVirViewport(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[109])(); }

int __stdcall FBroVIPControl_SetVirWebdriver(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[110])(); }

int __stdcall FBroVIPControl_SetVirWebglrenderer(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[111])(); }

int __stdcall FBroVIPControl_SetVirWebglvendor(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[112])(); }

int __stdcall FBroVIPControl_SetVirWebrtcIP(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[113])(); }

int __stdcall FBroVIPControl_SetVirisTrusted(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[114])(); }

int __stdcall FBroVIPControl_SetWebGLFingerPrint_constant(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[115])(); }

int __stdcall FBroVIPControl_SetWebGLFingerPrint_random(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[116])(); }

int __stdcall FBroVIPCountControl(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[117])(); }

int __stdcall FBroVIPGetRealPoint(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[118])(); }

int __stdcall FBroVIPGlobal_SetS5Auth(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[119])(); }

int __stdcall FBroVIPNewBountControl(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[120])(); }

int __stdcall FBroVIPNewClass(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[121])(); }

int __stdcall FBroVIPRequestContext_EnableExtensionPlus(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[122])(); }

int __stdcall FBroVIPResourceHandler_AddChangeData(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[123])(); }

int __stdcall FBroVIPResourceHandler_AddChangeFile(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[124])(); }

int __stdcall FBroVIPResourceHandler_DeleteAllData(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[125])(); }

int __stdcall FBroVIPResourceHandler_DeleteChangeData(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[126])(); }

int __stdcall FBroVIPResponseFilter_AddChangeData(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[127])(); }

int __stdcall FBroVIPResponseFilter_DeleteAllData(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[128])(); }

int __stdcall FBroVIPResponseFilter_DeleteChangeData(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[129])(); }

int __stdcall HookEVIPEvent(void) { init_ptrs(); return ((int(__stdcall*)())g_pfn[130])(); }

BOOL WINAPI DllMain(HINSTANCE h, DWORD r, LPVOID rv)
{
    if (r == DLL_PROCESS_ATTACH) DisableThreadLibraryCalls(h);
    return TRUE;
}

/*
 * .def file contents (save as dll_proxy.def):
 * EXPORTS
 *   FBroBrowser_GetExpirationTime
 *   FBroBrowser_GetFunctionStr
 *   FBroBrowser_GetMachineCode
 *   FBroBrowser_GetRegistrationTime
 *   FBroBrowser_GetVIPControl
 *   FBroBrowser_GetVersionStr
 *   FBroBrowser_IsLicenceKey
 *   FBroBrowser_SetLicenceKey
 *   FBroDevToolsDOM_disable
 *   FBroDevToolsDOM_discardSearchResults
 *   FBroDevToolsDOM_enable
 *   FBroDevToolsDOM_focusElement
 *   FBroDevToolsDOM_getAttributes
 *   FBroDevToolsDOM_getContainerForNode
 *   FBroDevToolsDOM_getDocument
 *   FBroDevToolsDOM_getOuterHTML
 *   FBroDevToolsDOM_getSearchResults
 *   FBroDevToolsDOM_performSearch
 *   FBroDevToolsDOM_querySelector
 *   FBroDevToolsDOM_querySelectorAll
 *   FBroDevToolsDOM_removeAttribute
 *   FBroDevToolsDOM_removeNode
 *   FBroDevToolsDOM_setAttributeValue
 *   FBroDevToolsDOM_setAttributesAsText
 *   FBroDevToolsDOM_setNodeName
 *   FBroDevToolsDOM_setNodeValue
 *   FBroDevToolsDOM_setOuterHTML
 *   FBroOnlineLicenseControl_GetError
 *   FBroOnlineLicenseControl_GetShowLicenseDevTool
 *   FBroOnlineLicenseControl_GetShowLicenseEndDate
 *   FBroOnlineLicenseControl_GetShowLicenseFunction
 *   FBroOnlineLicenseControl_GetShowLicenseStartDate
 *   FBroOnlineLicenseControl_GetShowLicenseSysVersion
 *   FBroOnlineLicenseControl_GetShowLicenseType
 *   FBroOnlineLicenseControl_SetKey
 *   FBroVIPBountControl
 *   FBroVIPControl_AddDevToolsMessageObserver
 *   FBroVIPControl_AddResourceHandlerChangeData
 *   FBroVIPControl_AddResourceHandlerChangeFile
 *   FBroVIPControl_AddResponseFilterChangeData
 *   FBroVIPControl_ClearAllData
 *   FBroVIPControl_ClearFingerCount
 *   FBroVIPControl_ClearS5Auth
 *   FBroVIPControl_DeletResponseFiltereChangeData
 *   FBroVIPControl_DeleteDevToolsMessageObserver
 *   FBroVIPControl_DeleteResourceHandlerAllData
 *   FBroVIPControl_DeleteResourceHandlerChangeData
 *   FBroVIPControl_DeleteResponseFilterAllData
 *   FBroVIPControl_DispatchKeyEvent
 *   FBroVIPControl_DispatchMouseEvent
 *   FBroVIPControl_DispatchTouchEvent
 *   FBroVIPControl_EnableWebsocketClientHook
 *   FBroVIPControl_ExecuteDevToolsMethod
 *   FBroVIPControl_GetBrowser
 *   FBroVIPControl_GetBrowserPtr
 *   FBroVIPControl_GetFingerCount
 *   FBroVIPControl_PageCaptureScreenshot
 *   FBroVIPControl_PageGetContextID
 *   FBroVIPControl_RuntimeEnable
 *   FBroVIPControl_RuntimeEvaluate
 *   FBroVIPControl_RuntimeEvaluate_FrameID
 *   FBroVIPControl_SendDevToolsMessage
 *   FBroVIPControl_SetAudioFingerPrint_constant
 *   FBroVIPControl_SetAudioFingerPrint_random
 *   FBroVIPControl_SetCanvasFingerPrint_constant
 *   FBroVIPControl_SetCanvasFingerPrint_random
 *   FBroVIPControl_SetDisableConsoleDebug
 *   FBroVIPControl_SetDisableDebugger
 *   FBroVIPControl_SetEmitTouchEventsForMouse
 *   FBroVIPControl_SetPlugins
 *   FBroVIPControl_SetS5Auth
 *   FBroVIPControl_SetSSLCipher
 *   FBroVIPControl_SetTouchEventEmulationEnabled
 *   FBroVIPControl_SetVirAcceptlanguages
 *   FBroVIPControl_SetVirAppCodeName
 *   FBroVIPControl_SetVirAppName
 *   FBroVIPControl_SetVirAppVersion
 *   FBroVIPControl_SetVirAudioInput
 *   FBroVIPControl_SetVirAudioOutput
 *   FBroVIPControl_SetVirBatteryManagerCharging
 *   FBroVIPControl_SetVirBatteryManagerChargingTime
 *   FBroVIPControl_SetVirBatteryManagerDischargingTime
 *   FBroVIPControl_SetVirBatteryManagerLevel
 *   FBroVIPControl_SetVirCSSFontFingerprint
 *   FBroVIPControl_SetVirCanvas2DFontFingerprint
 *   FBroVIPControl_SetVirCookieEnabled
 *   FBroVIPControl_SetVirDeviceMemory
 *   FBroVIPControl_SetVirDevicePixelRatio
 *   FBroVIPControl_SetVirHardwareConcurrency
 *   FBroVIPControl_SetVirJavaEnabled
 *   FBroVIPControl_SetVirKernel
 *   FBroVIPControl_SetVirLanguages
 *   FBroVIPControl_SetVirLongitudeAndLatitude
 *   FBroVIPControl_SetVirOnLine
 *   FBroVIPControl_SetVirOrientation
 *   FBroVIPControl_SetVirPlatform
 *   FBroVIPControl_SetVirProduct
 *   FBroVIPControl_SetVirProductSub
 *   FBroVIPControl_SetVirRectFingerprint
 *   FBroVIPControl_SetVirScreenHeightAndWidth
 *   FBroVIPControl_SetVirScreenXAndY
 *   FBroVIPControl_SetVirScreenavailHeightAndWidth
 *   FBroVIPControl_SetVirScreencolorDepth
 *   FBroVIPControl_SetVirScreenpixelDepth
 *   FBroVIPControl_SetVirTimeZone
 *   FBroVIPControl_SetVirUserAgent
 *   FBroVIPControl_SetVirVendor
 *   FBroVIPControl_SetVirVendorSub
 *   FBroVIPControl_SetVirVideoInput
 *   FBroVIPControl_SetVirViewport
 *   FBroVIPControl_SetVirWebdriver
 *   FBroVIPControl_SetVirWebglrenderer
 *   FBroVIPControl_SetVirWebglvendor
 *   FBroVIPControl_SetVirWebrtcIP
 *   FBroVIPControl_SetVirisTrusted
 *   FBroVIPControl_SetWebGLFingerPrint_constant
 *   FBroVIPControl_SetWebGLFingerPrint_random
 *   FBroVIPCountControl
 *   FBroVIPGetRealPoint
 *   FBroVIPGlobal_SetS5Auth
 *   FBroVIPNewBountControl
 *   FBroVIPNewClass
 *   FBroVIPRequestContext_EnableExtensionPlus
 *   FBroVIPResourceHandler_AddChangeData
 *   FBroVIPResourceHandler_AddChangeFile
 *   FBroVIPResourceHandler_DeleteAllData
 *   FBroVIPResourceHandler_DeleteChangeData
 *   FBroVIPResponseFilter_AddChangeData
 *   FBroVIPResponseFilter_DeleteAllData
 *   FBroVIPResponseFilter_DeleteChangeData
 *   HookEVIPEvent
 */
// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include "fieldofview.h"

DWORD WINAPI MainThread() {

    fieldofview::init_hooks();

    return 0;

};

BOOL InitInstance() {

    if (MH_Initialize() != MH_OK) {

        ExitProcess(0xDEADBEEF);

    };

    if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {

        ExitProcess(0xBEEEEEEF);

    };

    MainThread();

    return true;

};

BOOL ExitInstance() {
    return true;
};

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        FILE* fp;
        AllocConsole();
        SetConsoleTitleA("fieldofview");
        freopen_s(&fp, "CONOUT$", "w", stdout);
        //printf("HELLO IM HERE \n");
        InitInstance();
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


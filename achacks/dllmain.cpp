#include "cheats.h"

BOOL APIENTRY DllMain(const HMODULE hModule, const DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        HANDLE handle;
        handle = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) &cheatLoop, hModule, 0, nullptr);
        CloseHandle(handle);
    }
    return TRUE;
}

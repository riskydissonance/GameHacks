#include <tchar.h>
#include <cheat/cheatlist.h>
#include <utils/utils.h>
#include "cheats.h"
#include "cheats/packet_capture.h"

void __stdcall cheatLoop(const HMODULE hModule) {

    logging::Logger* logger = new logging::DebugLogger{};
    logger->info_log(_T("[+] Cheat DLL Loaded"));

    uintptr_t baseAddress = getBaseAddress();
    logger->debug_log(_T("[*] Main module base address at 0x%p"), baseAddress);

    native::NativeFunctions* nativeFunctions = new native::WinAPI{};
    auto mem = new mem::Mem{ *logger, *nativeFunctions };

    auto cheatList = new cheat::CheatList{ *logger };
    cheatList->registerCheat(VK_INSERT, new cheat::PacketCapture{ baseAddress, *mem, *logger });

    while (true) {

        if (GetAsyncKeyState(VK_INSERT) & 0x01) {
            cheatList->toggle(VK_INSERT);
        }

        if (GetAsyncKeyState(VK_END) & 0x01) {
            cheatList->toggle(NULL);
            break;
        }

        Sleep(10); // TODO hook game loop so don't have to sleep
    }

    logger->info_log(_T("[*] Disabling cheats and unloading DLL"));

    delete cheatList;
    delete mem;
    delete nativeFunctions;
    logger->debug_log(_T("[*] Done, the logger is the last thing to go... goodbye..."));
    delete logger;

    FreeLibraryAndExitThread(hModule, 0);
}

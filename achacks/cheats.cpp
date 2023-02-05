#include <tchar.h>
#include <cheat/cheatlist.h>
#include <utils/utils.h>
#include "cheats.h"
#include "cheats/health.h"
#include "cheats/ammo.h"
#include "cheats/recoil.h"
#include "cheats/fly.h"
#include "cheats/esp.h"
#include "cheats/noclip.h"
#include "cheats/radar.h"
#include "cheats/states/triggerbot.h"
#include "logging/chat.h"
#include "cheats/states/aimbot.h"

void __stdcall cheatLoop(const HMODULE hModule) {


    logging::Logger* logger = new logging::DebugLogger{  };
    logger->info_log(_T("[+] Cheat DLL Loaded"));
    uintptr_t baseAddress = getBaseAddress();
    logger->debug_log(_T("[*] Main module base address at 0x%p"), baseAddress);

    native::NativeFunctions* nativeFunctions = new native::WinAPI{};
    auto mem = new mem::Mem{ *logger, *nativeFunctions };

    const auto playerAddress = *(uintptr_t**) (baseAddress + PLAYER_POINTER_OFFSET);

    auto pPlayer = (playerent*)(*playerAddress);

    while (!pPlayer) {
        pPlayer = (playerent*)(*playerAddress);
        Sleep(1000);
    }

    logger->debug_log(_T("[*] Player at: 0x%p"), pPlayer);

    auto cheatList = new cheat::CheatList{ *logger };
    cheatList->registerCheat(VK_INSERT, new cheat::Health{ baseAddress, pPlayer, *mem, *logger });
    cheatList->registerCheat(VK_INSERT, new cheat::Ammo{ baseAddress, pPlayer, *mem, *logger });
    //cheatList->registerCheat(VK_INSERT, new cheat::Recoil{ baseAddress, pPlayer, *mem, *logger });
    //cheatList->registerCheat(VK_INSERT, new cheat::Fly{ baseAddress, pPlayer, *mem, *logger });
    //cheatList->registerCheat(VK_INSERT, new cheat::RadarESP{ baseAddress, pPlayer, *mem, *logger });
    //cheatList->registerCheat(VK_INSERT, new cheat::ESP{ baseAddress, pPlayer, *mem, *logger });
    //cheatList->registerCheat(VK_HOME, new cheat::NoClip{ baseAddress, pPlayer, *mem, *logger });

    //auto stateMachine = new state::StateMachine{ *logger };
    //stateMachine->registerState(VK_INSERT, new cheats::states::TriggerBotState{ baseAddress, pPlayer, *mem, *logger });
    //stateMachine->registerState(VK_F2, new cheats::states::AimBotState{ baseAddress, pPlayer, *mem, *logger });

    while (true) {

        if (GetAsyncKeyState(VK_INSERT) & 0x01) {
            cheatList->toggle(VK_INSERT);
           // stateMachine->toggle(VK_INSERT);
        }

        if (GetAsyncKeyState(VK_HOME) & 0x01) {
            cheatList->toggle(VK_HOME);
            //stateMachine->toggle(VK_HOME);
        }

        if (GetAsyncKeyState(VK_F2) & 0x01) {
            cheatList->toggle(VK_F2);
           //stateMachine->toggle(VK_F2);
        }

        if (GetAsyncKeyState(VK_END) & 0x01) {
            cheatList->toggle(NULL);
            //stateMachine->toggle(NULL);
            break;
        }

        //stateMachine->incrementState();

        Sleep(10); // TODO hook game loop so don't have to sleep
    }

    logger->info_log(_T("[*] Disabling cheats and unloading DLL"));

    delete cheatList;
   // delete stateMachine;
    delete mem;
    delete nativeFunctions;
    logger->debug_log(_T("[*] Done, the logger is the last thing to go... goodbye..."));
    delete logger;
    FreeLibraryAndExitThread(hModule, 0);
}

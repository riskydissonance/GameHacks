#include "cheats.h"
#include "cheats/health.h"
#include "cheats/ammo.h"
#include "cheats/recoil.h"
#include "cheats/movement.h"
#include "cheats/radar.h"
#include "cheats/states/triggerbot.h"
#include "logging/chat.h"
#include "cheats/states/aimbot.h"
#include <tchar.h>

extern uintptr_t __cdecl getBaseAddress();

void __stdcall cheatLoop(const HMODULE hModule) {

    native::NativeFunctions* nativeFunctions = new native::WinAPI{};
    auto mem = new mem::Mem{ *nativeFunctions };

    uintptr_t baseAddress = getBaseAddress();

    logging::Logger* logger = new logging::ACChatLogger{ baseAddress };
    logger->info_log(_T("[+] Cheat DLL Loaded"));
    logger->debug_log(_T("[*] Main module base address at 0x%p"), baseAddress);

    const auto playerAddress = (uintptr_t*) (baseAddress + PLAYER_POINTER_OFFSET);

    auto pPlayer = reinterpret_cast<playerent*>(*playerAddress);

    while(!pPlayer)
        pPlayer = reinterpret_cast<playerent*>(*playerAddress);

    logger->debug_log(_T("[*] Player at: 0x%p"), pPlayer);

    auto cheatsEnabled = false;
    auto noClipEnabled = false;
    auto aimbotEnabled = false;

    auto stateMachine = new state::StateMachine{ *logger };

    auto healthCheat = new cheats::Health{ baseAddress, pPlayer, *mem, *logger };
    auto ammoCheat = new cheats::Ammo{ baseAddress, pPlayer, *mem, *logger };
    auto recoilCheat = new cheats::Recoil{ baseAddress, pPlayer, *mem, *logger };
    auto movementCheat = new cheats::Movement{ baseAddress, pPlayer, *mem, *logger };
    auto radarESPCheat = new cheats::RadarESP{ baseAddress, pPlayer, *mem, *logger };

    auto triggerBotCheat = new cheats::states::TriggerBot{ baseAddress, pPlayer, *mem, *logger, *stateMachine };
    auto aimBotCheat = new cheats::states::AimBot{ baseAddress, pPlayer, *mem, *logger, *stateMachine };

    while (true) {

        if (GetAsyncKeyState(VK_INSERT) & 0x01) {
            cheatsEnabled = !cheatsEnabled;
            if (cheatsEnabled) {
                logger->info_log(_T("[+] Cheats enabled"));
            } else {
                logger->info_log(_T("[+] Cheats disabled"));
            }
            movementCheat->toggleFly(cheatsEnabled);
            healthCheat->toggleInfiniteHealth(cheatsEnabled);
            ammoCheat->toggleInfiniteAmmo(cheatsEnabled);
            recoilCheat->toggleNoRecoil(cheatsEnabled);
            radarESPCheat->toggleRadarESP(cheatsEnabled);

            // Build state machine, in order of priority
            triggerBotCheat->toggleTriggerBot(cheatsEnabled);
        }

        if (GetAsyncKeyState(VK_HOME) & 0x01) {
            noClipEnabled = !noClipEnabled;
            if (noClipEnabled) {
                logger->info_log(_T("[+] NoClip enabled"));
            } else {
                logger->info_log(_T("[+] NoClip disabled"));
            }
            movementCheat->toggleNoClip(noClipEnabled);
        }

        if (GetAsyncKeyState(VK_F2) & 0x01) {
            logger->info_log(_T("[+] Enabling aimbot"));
            aimbotEnabled = !aimbotEnabled;
            aimBotCheat->toggleAimBot(aimbotEnabled);
        }

        if (GetAsyncKeyState(VK_END) & 0x01) {
            movementCheat->toggleNoClip(false);
            movementCheat->toggleFly(false);
            healthCheat->toggleInfiniteHealth(false);
            ammoCheat->toggleInfiniteAmmo(false);
            recoilCheat->toggleNoRecoil(false);
            radarESPCheat->toggleRadarESP(false);
            triggerBotCheat->toggleTriggerBot(false);
            aimBotCheat->toggleAimBot(false);
            break;
        }

        if (cheatsEnabled) {
            stateMachine->incrementState();
        }

        Sleep(10);
    }

    logger->info_log(_T("[*] Disabling cheats and unloading DLL"));

    delete triggerBotCheat;
    delete aimBotCheat;
    delete radarESPCheat;
    delete healthCheat;
    delete ammoCheat;
    delete recoilCheat;
    delete movementCheat;
    delete stateMachine;
    delete mem;
    delete nativeFunctions;
    logger->debug_log(_T("[*] Done, the logger is the last thing to go... goodbye..."));
    delete logger;
    FreeLibraryAndExitThread(hModule, 0);
}

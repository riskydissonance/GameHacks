#include "cheats.h"
#include "cheats/health.h"
#include "cheats/ammo.h"
#include "cheats/recoil.h"
#include "cheats/movement.h"
#include "cheats/chat.h"
#include "cheats/triggerbot.h"
#include <tchar.h>
#include <list>

extern uintptr_t __cdecl getBaseAddress();

void __stdcall cheatLoop(const HMODULE hModule) {

    native::NativeFunctions* nativeFunctions = new native::WinAPI{};
    auto mem = new mem::Mem{ *nativeFunctions };

    uintptr_t baseAddress = getBaseAddress();

    logging::Logger* logger = new logging::ACChatLogger{ baseAddress };

    logger->debug_log(_T("[*] Main module base address at 0x%x, 0x%p"), baseAddress, baseAddress);

    const auto playerAddress = (uintptr_t*) (baseAddress + 0x10F4F4);
    logger->debug_log(_T("[*] Player at: 0x%x"), playerAddress);

    auto pPlayer = reinterpret_cast<playerent*>(*playerAddress);

    auto cheatsEnabled = false;
    auto noClipEnabled = false;

    std::list<_cheatLoopFunc> cheatLoopFuncs = {};

    auto healthCheat = new cheats::Health{ baseAddress, pPlayer, *mem, *logger };
    auto ammoCheat = new cheats::Ammo{ baseAddress, pPlayer, *mem, *logger };
    auto recoilCheat = new cheats::Recoil{ baseAddress, pPlayer, *mem, *logger };
    auto movementCheat = new cheats::Movement{ baseAddress, pPlayer, *mem, *logger };
    auto triggerBotCheat = new cheats::TriggerBot{ baseAddress, pPlayer, *mem, *logger, cheatLoopFuncs };

    while (true) {

        if (GetAsyncKeyState(VK_INSERT) & 0x01) {
            cheatsEnabled = !cheatsEnabled;
            movementCheat->toggleFly(cheatsEnabled);
            healthCheat->toggleInfiniteHealth(cheatsEnabled);
            ammoCheat->toggleInfiniteAmmo(cheatsEnabled);
            recoilCheat->toggleNoRecoil(cheatsEnabled);
            triggerBotCheat->toggleTriggerBot(cheatsEnabled);
        }

        if (GetAsyncKeyState(VK_HOME) & 0x01) {
            noClipEnabled = !noClipEnabled;
            movementCheat->toggleNoClip(noClipEnabled);
        }

        if (GetAsyncKeyState(VK_END) & 0x01) {
            movementCheat->toggleNoClip(false);
            movementCheat->toggleFly(false);
            healthCheat->toggleInfiniteHealth(false);
            ammoCheat->toggleInfiniteAmmo(false);
            recoilCheat->toggleNoRecoil(false);
            triggerBotCheat->toggleTriggerBot(false);
            break;
        }

        if (cheatsEnabled) {
            for (_cheatLoopFunc cheatLoopFunc : cheatLoopFuncs) {
                if (cheatLoopFunc) {
                    cheatLoopFunc(baseAddress, pPlayer, *mem, *logger);
                }
            }
        }

        Sleep(30);
    }

    logger->debug_log(_T("[*] Exiting, cleaning up resources..."));

    delete triggerBotCheat;
    delete healthCheat;
    delete ammoCheat;
    delete recoilCheat;
    delete movementCheat;
    delete mem;
    delete nativeFunctions;
    logger->debug_log(_T("[*] Done, the logger is the last thing to go... goodbye..."));
    delete logger;
    FreeLibraryAndExitThread(hModule, 0);
}

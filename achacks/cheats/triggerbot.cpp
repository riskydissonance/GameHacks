#include "triggerbot.h"

void triggerBotLoopFunc(const uintptr_t& baseAddress, const uintptr_t* pPlayer, const mem::Mem& mem, const logging::Logger& logger) {
    auto traceline = (cheats::TriggerBot::_traceline) (baseAddress + cheats::TriggerBot::TRACELINE_FUNC_OFFSET);
    auto pTargetedEnt = traceline();
    if (pTargetedEnt) {
        if (pTargetedEnt->Team != ((playerent*)pPlayer)->Team) {
            ((playerent*)pPlayer)->AutomaticFiring = 1;
        }
    } else {
        ((playerent*)pPlayer)->AutomaticFiring = 0;
    }
}

bool cheats::TriggerBot::toggleTriggerBot(const bool enabled) {
    if (enabled) {
        cheatLoopFuncs.registerLoopFunc((cheatloop::CheatLoop::_cheatLoopFunc) &triggerBotLoopFunc);
        logger.debug_log(_T("[+] TriggerBot enabled"));
    } else {
        cheatLoopFuncs.unregisterLoopFunc((cheatloop::CheatLoop::_cheatLoopFunc) &triggerBotLoopFunc);
        pPlayer->AutomaticFiring = 0;
        logger.debug_log(_T("[+] TriggerBot disabled"));
    }
    return true;
}

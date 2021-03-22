#include "triggerbot.h"

void triggerBotLoopFunc(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) {
    auto traceline = (cheats::TriggerBot::_traceline) (baseAddress + cheats::TriggerBot::TRACELINE_FUNC_OFFSET);
    if (traceline()) {
        pPlayer->AutomaticFiring = 1;
    } else {
        pPlayer->AutomaticFiring = 0;
    }
}

bool cheats::TriggerBot::toggleTriggerBot(const bool enabled) {
    if (enabled) {
        cheatLoopFuncs.push_back((_cheatLoopFunc) &triggerBotLoopFunc);
        logger.debug_log(_T("[+] TriggerBot enabled"));
    } else {
        cheatLoopFuncs.remove((_cheatLoopFunc) &triggerBotLoopFunc);
        pPlayer->AutomaticFiring = 0;
        logger.debug_log(_T("[+] TriggerBot disabled"));
    }
    return true;
}

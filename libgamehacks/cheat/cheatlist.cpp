#include "cheatlist.h"

void cheat::CheatList::registerCheat(KEY key, Cheat* cheat) {
    if (keyCheatMap.contains(key)) {
        keyCheatMap[key].push_back(cheat);
    } else {
        keyCheatMap[key] = std::list<Cheat*>{};
        keyCheatMap[key].push_back(cheat);
        keyEnabledMap[key] = false;
    }
    logger.debug_log(_T("[+] Registered cheat: %s"), cheat->getName());
}

void cheat::CheatList::toggle(KEY toggleKey) {
    if (toggleKey == NULL) {
        for (const auto& cheatList : keyCheatMap) {
            for (auto cheat : cheatList.second) {
                if (cheat) {
                    keyEnabledMap[toggleKey] = false;
                    cheat->toggle(false);
                }
            }
        }
        logger.debug_log(_T("[*] All cheats disabled"));
    } else {
        if (keyCheatMap.contains(toggleKey)) {
            auto newState = !keyEnabledMap[toggleKey];
            keyEnabledMap[toggleKey] = newState;
            for (auto cheat : keyCheatMap[toggleKey]) {
                if (cheat) {
                    cheat->toggle(newState);
                }
            }
            logger.debug_log(_T("[*] Cheat key %d toggled to %d"), toggleKey, newState);
        }
    }
}

#include "triggerbot.h"

bool cheats::TriggerBotState::condition() {
    lastTracelineResult = traceline();
    if (lastTracelineResult) {
        return false;
    }
    return true;
}

bool cheats::TriggerBotState::reach() {
    if (lastTracelineResult) {
        if (lastTracelineResult->Team != pPlayer->Team) {
            pPlayer->AutomaticFiring = 1;
            wasFiring = true;
        }
    }
    return true;
}

bool cheats::TriggerBotState::reached() {
    if(wasFiring){
        pPlayer->AutomaticFiring = 0;
        wasFiring = false;
    }
    return true;
}

const TCHAR* cheats::TriggerBotState::getName() const {
    return name;
}

bool cheats::TriggerBot::toggleTriggerBot(bool enabled) {
    if (enabled) {
        stateMachine.registerState(triggerBotState);
        logger.debug_log(_T("Registered TriggerBot state"));
    } else {
        stateMachine.unregisterState(triggerBotState);
        pPlayer->AutomaticFiring = 0;
        logger.debug_log(_T("Unregistered TriggerBot state"));
    }
    return true;
}

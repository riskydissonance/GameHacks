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
            // TODO find fire weapon function as opposed to toggling state
            Sleep(1);
            pPlayer->AutomaticFiring = 0;
        } else {
            pPlayer->AutomaticFiring = 0;
        }
    }
    return true;
}

const TCHAR* cheats::TriggerBotState::get_name() const {
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

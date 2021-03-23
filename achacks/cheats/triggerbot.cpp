#include "triggerbot.h"

bool cheats::TriggerBotState::condition() const {
    // TODO make last targetedEnt a variable
    auto traceline = (cheats::TriggerBot::_traceline) (baseAddress + cheats::TriggerBot::TRACELINE_FUNC_OFFSET);
    auto pTargetedEnt = traceline();
    if (pTargetedEnt) {
        return false;
    }
    return true;
}

bool cheats::TriggerBotState::reach() {
    auto traceline = (cheats::TriggerBot::_traceline) (baseAddress + cheats::TriggerBot::TRACELINE_FUNC_OFFSET);
    auto pTargetedEnt = traceline();
    if (pTargetedEnt) {
        if (pTargetedEnt->Team != ((playerent*) pPlayer)->Team) {
            ((playerent*) pPlayer)->AutomaticFiring = 1;
            // TODO find fire weapon function as opposed to toggling state
            Sleep(1);
            ((playerent*) pPlayer)->AutomaticFiring = 0;
        } else {
            ((playerent*) pPlayer)->AutomaticFiring = 0;
        }
    } else {
        ((playerent*) pPlayer)->AutomaticFiring = 0;
    }
    return true;
}

const TCHAR* cheats::TriggerBotState::get_name() const {
    return name;
}

bool cheats::TriggerBot::toggleTriggerBot(bool enabled) {
    if (enabled) {
        stateMachine.registerState(triggerBotState);
        logger.debug_log("Registered TriggerBot state");
    } else {
        stateMachine.unregisterState(triggerBotState);
        pPlayer->AutomaticFiring = 0;
        logger.debug_log("Unregistered TriggerBot state");
    }
    return true;
}

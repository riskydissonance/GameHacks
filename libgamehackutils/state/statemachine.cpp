#include "statemachine.h"

void state::StateMachine::registerState(KEY key, State* state) {
    if (keyStateMap.contains(key)) {
        keyStateMap[key].push_back(state);
    } else {
        keyStateMap[key] = std::list<State*>{};
        keyStateMap[key].push_back(state);
        keyEnabledMap[key] = false;
    }
    logger.debug_log(_T("[+] Registered state: %s"), state->getName());
}

void state::StateMachine::toggle(KEY toggleKey) {
    if (toggleKey == NULL) {
        for (const auto& cheatList : keyStateMap) {
            for (auto state : cheatList.second) {
                if (state) {
                    keyEnabledMap[toggleKey] = false;
                }
            }
        }
        logger.debug_log(_T("[*] All states disabled"));
    } else {
        if (keyStateMap.contains(toggleKey)) {
            auto newState = !keyEnabledMap[toggleKey];
            keyEnabledMap[toggleKey] = newState;
            logger.debug_log(_T("[*] State key %d toggled to %d"), toggleKey, newState);
        }
    }
}

void state::StateMachine::incrementState() {
    for (auto key : keyEnabledMap) {
        if (key.second) {
            for (auto state : keyStateMap[key.first]) {
                if (state) {
                    if (state->condition()) {
                        state->reached();
                    } else {
                        state->reach();
                        break;
                    }
                }
            }
        }
    }
}

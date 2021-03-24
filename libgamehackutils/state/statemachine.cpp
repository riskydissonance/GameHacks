#include "statemachine.h"

void state::StateMachine::registerState(State* state) {
    states.push_back(state);
    logger.debug_log(_T("Registered state: %s"), state->getName());
}

void state::StateMachine::unregisterState(State* state) {
    states.remove(state);
    logger.debug_log(_T("Unregistered state: %s"), state->getName());
}

void state::StateMachine::incrementState() {
    for (auto state : states) {
        if (state) {
            if(state->condition()){
                state->reached();
            } else {
                state->reach();
                break;
            }
        }
    }
}

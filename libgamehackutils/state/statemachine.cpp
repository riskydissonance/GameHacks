#include "statemachine.h"

void state::StateMachine::registerState(State* state) {
    states.push_back(state);
    logger.debug_log(_T("Registered state: %s"), state->get_name());
}

void state::StateMachine::unregisterState(State* state) {
    states.remove(state);
    logger.debug_log(_T("Unregistered state: %s"), state->get_name());
}

void state::StateMachine::incrementState() {
    for (auto state : states) {
        if (state && !state->condition()) {
            logger.debug_log(_T("State not met, executing reach: %s"), state->get_name());
            state->reach();
            break;
        }
    }
}

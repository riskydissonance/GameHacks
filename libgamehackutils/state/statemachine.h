#pragma once

#include "state.h"
#include <list>

namespace state {

    class StateMachine {

    public:

        StateMachine(const logging::Logger& logger) :
                logger{ logger } {
            states = {};
        }

        ~StateMachine() = default;

        void registerState(State* state);

        void unregisterState(State* state);

        void incrementState();

    private:
        const logging::Logger& logger;
        std::list<State*> states;

    };

}

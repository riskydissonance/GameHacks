#pragma once

#include <list>
#include <map>
#include "state.h"

namespace state {

    class StateMachine {

    public:

        typedef BYTE KEY;

        explicit StateMachine(const logging::Logger& logger) :
                logger{ logger } {
            keyStateMap = {};
            keyEnabledMap = {};
        }

        ~StateMachine() {
            for (auto& keyStates : keyStateMap) {
                for (auto state : keyStates.second) {
                    delete state;
                }
            }
        };

        void registerState(KEY, State* state);

        void incrementState();

        void toggle(KEY toggleKey);

    private:
        const logging::Logger& logger;
        std::map<KEY, std::list<State*>> keyStateMap;
        std::map<KEY, bool> keyEnabledMap;

    };

}

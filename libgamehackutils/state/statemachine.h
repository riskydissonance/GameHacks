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

        /**
         * Registers the state in the state machine.
         *
         * Resource cleanup of the state is handled by this state machine class.
         *
         * @param state - the state to register.
         */
        void registerState(KEY, State* state);

        void incrementState();

        /**
         * Toggles the cheats.
         *
         * @param toggleKey - The VK key to toggle, or NULL to turn all keys off.
         */
        void toggle(KEY toggleKey);

    private:
        const logging::Logger& logger;
        std::map<KEY, std::list<State*>> keyStateMap;
        std::map<KEY, bool> keyEnabledMap;

    };

}

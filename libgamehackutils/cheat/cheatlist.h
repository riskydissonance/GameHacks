#pragma once

#include <list>
#include <map>
#include "cheat.h"

namespace cheat {

    class CheatList {

    public:

        typedef BYTE KEY;

        explicit CheatList(const logging::Logger& logger) :
                logger{ logger } {
            keyCheatMap = {};
            keyEnabledMap = {};
        }

        ~CheatList() {
            for (auto& keyCheats : keyCheatMap) {
                for (auto cheat : keyCheats.second) {
                    delete cheat;
                }
            }
        };

        /**
         * Registers the cheat in the cheat list.
         *
         * @param cheat - the cheat to register. Resource cleanup of the cheat is handled by this cheat list class.
         */
        void registerCheat(KEY, Cheat* cheat);

        /**
         * Toggles the cheats.
         *
         * @param toggleKey - The VK key to toggle, or NULL to turn all keys off.
         */
        void toggle(KEY toggleKey);

    private:
        const logging::Logger& logger;
        std::map<KEY, std::list<Cheat*>> keyCheatMap;
        std::map<KEY, bool> keyEnabledMap;

    };

}

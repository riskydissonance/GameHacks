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

        void registerCheat(KEY, Cheat* state);

        void toggle(KEY toggleKey);

    private:
        const logging::Logger& logger;
        std::map<KEY, std::list<Cheat*>> keyCheatMap;
        std::map<KEY, bool> keyEnabledMap;

    };

}

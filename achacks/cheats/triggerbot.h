#pragma once

#include "../reclass/playerent.h"
#include "../cheats.h"
#include <state/cheatloop.h>
#include <list>

namespace cheats {

    class TriggerBot {

    public:

        static const uintptr_t TRACELINE_FUNC_OFFSET = 0x0607C0;

        const typedef playerent* (__cdecl* _traceline)();

        TriggerBot(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger,
                   cheatloop::CheatLoop& cheatLoopFuncs) :
                baseAddress{ baseAddress },
                pPlayer{ pPlayer },
                logger{ logger },
                mem{ mem },
                cheatLoopFuncs{ cheatLoopFuncs } {
        }

        ~TriggerBot();

        bool toggleTriggerBot(bool enabled);

    private:
        const uintptr_t baseAddress;
        playerent* pPlayer;
        const mem::Mem& mem;
        const logging::Logger& logger;
        cheatloop::CheatLoop& cheatLoopFuncs;

    };

}

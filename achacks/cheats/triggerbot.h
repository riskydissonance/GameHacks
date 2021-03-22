#pragma once

#include "../playerent.h"
#include "../cheats.h"
#include <list>

namespace cheats {

    class TriggerBot {

    public:

        static const uintptr_t TRACELINE_FUNC_OFFSET = 0x0607C0;

        const typedef int (__cdecl* _traceline)();

        TriggerBot(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger,
                   std::list<_cheatLoopFunc>& cheatLoopFuncs) :
                baseAddress{ baseAddress },
                pPlayer{ pPlayer },
                logger{ logger },
                mem{ mem },
                cheatLoopFuncs{ cheatLoopFuncs } {
        }

        ~TriggerBot() = default;

        bool toggleTriggerBot(bool enabled);

    private:
        const uintptr_t baseAddress;
        playerent* pPlayer;
        const mem::Mem& mem;
        const logging::Logger& logger;
        std::list<_cheatLoopFunc>& cheatLoopFuncs;

    };

}

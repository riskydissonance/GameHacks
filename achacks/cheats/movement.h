#pragma once

#include "../playerent.h"

namespace cheats {

    class Movement {

    public:

        Movement(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                    baseAddress { baseAddress },
                    pPlayer { pPlayer },
                    logger { logger },
                    mem { mem } {
            }

        ~Movement()= default;

        bool toggleFly(bool enabled);
        bool toggleNoClip(bool enabled);


    private:
        const uintptr_t baseAddress;
        playerent* pPlayer;
        const mem::Mem& mem;
        const logging::Logger& logger;

    };

}

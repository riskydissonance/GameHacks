#pragma once

#include "../playerent.h"

namespace cheats {

    class Recoil {

    public:

        Recoil(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                baseAddress{ baseAddress },
                pPlayer{ pPlayer },
                logger{ logger },
                mem{ mem } {
            originalRecoilHookBytes = nullptr;
        }

        ~Recoil() {
            delete[] originalRecoilHookBytes;
        }

        bool toggleNoRecoil(bool enabled);

    private:
        const uintptr_t baseAddress;
        playerent* pPlayer;
        const mem::Mem& mem;
        const logging::Logger& logger;
        BYTE* originalRecoilHookBytes;

    };
}

#pragma once

#include "../playerent.h"

static const int NOP_LENGTH = 2;

namespace cheats {

    class Ammo {

    public:

        Ammo(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                baseAddress{ baseAddress },
                pPlayer{ pPlayer },
                logger{ logger },
                mem{ mem } {
            originalAmmoDecrementBytes = nullptr;
            originalGrenadeDecrementBytes = nullptr;
        }

        ~Ammo() {
            delete[] originalAmmoDecrementBytes;
            delete[] originalGrenadeDecrementBytes;
        }

        bool toggleInfiniteAmmo(bool enabled);

    private:
        const uintptr_t baseAddress;
        playerent* pPlayer;
        const mem::Mem& mem;
        const logging::Logger& logger;
        BYTE* originalAmmoDecrementBytes;
        BYTE* originalGrenadeDecrementBytes;

    };
}

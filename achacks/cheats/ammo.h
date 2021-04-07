#pragma once

#include <cheat/cheat.h>
#include "../reclass/playerent.h"

namespace cheat {

    class Ammo : public Cheat {

    public:

        Ammo(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                Cheat(_T("Infinite Ammo"), baseAddress, mem, logger),
                pPlayer{ pPlayer }{
            originalAmmoDecrementBytes = nullptr;
            originalGrenadeDecrementBytes = nullptr;
        }

        ~Ammo() override {
            delete[] originalAmmoDecrementBytes;
            delete[] originalGrenadeDecrementBytes;
        }

        bool toggle(bool enabled) override;

    private:

        static const int NOP_LENGTH = 2;

        playerent* pPlayer;
        BYTE* originalAmmoDecrementBytes;
        BYTE* originalGrenadeDecrementBytes;

    };
}

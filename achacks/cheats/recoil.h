#pragma once

#include "../reclass/playerent.h"

namespace cheats {

    static const int RECOIL_NOP_LENGTH = 10;

    class Recoil {

    public:
        Recoil(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                baseAddress{ baseAddress },
                pPlayer{ pPlayer },
                logger{ logger },
                mem{ mem } {
            originalRecoilNopBytes = nullptr;
        }

        ~Recoil() {
            delete[] originalRecoilNopBytes;
        }

        bool toggleNoRecoil(bool enabled);

    private:
        const uintptr_t baseAddress;
        playerent* pPlayer;
        const mem::Mem& mem;
        const logging::Logger& logger;
        BYTE* originalRecoilNopBytes;

    };
}

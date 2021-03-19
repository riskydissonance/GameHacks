#pragma once

#include "../playerent.h"

namespace cheats {

    static const uintptr_t RECOIL_NOP_OFFSET = 0x63786;
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

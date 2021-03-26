#pragma once

#include "../reclass/playerent.h"

namespace cheats {

    class RadarESP {

    public:

        RadarESP(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                baseAddress{ baseAddress },
                pPlayer{ pPlayer },
                logger{ logger },
                mem{ mem } {
            originalRadarNopBytes = nullptr;
        }

        ~RadarESP() {
            delete[] originalRadarNopBytes;
        }

        bool toggleRadarESP(bool enabled);

    private:

        static const int NOP_LENGTH = 25;

        const uintptr_t baseAddress;
        playerent* pPlayer;
        const mem::Mem& mem;
        const logging::Logger& logger;
        BYTE* originalRadarNopBytes;

    };
}

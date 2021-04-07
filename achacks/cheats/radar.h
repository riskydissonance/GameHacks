#pragma once

#include <cheat/cheat.h>
#include "../reclass/playerent.h"

namespace cheat {

    class RadarESP : public Cheat {

    public:

        RadarESP(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                Cheat(_T("Radar ESP"), baseAddress, mem, logger),
                pPlayer{ pPlayer } {
            originalRadarNopBytes = nullptr;
        }

        ~RadarESP() override {
            delete[] originalRadarNopBytes;
        }

        bool toggle(bool enabled) override;

    private:

        static const int NOP_LENGTH = 25;

        playerent* pPlayer;
        BYTE* originalRadarNopBytes;

    };
}

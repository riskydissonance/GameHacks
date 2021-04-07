#pragma once

#include <cheat/cheat.h>
#include "../reclass/playerent.h"

namespace cheat {

    static const int RECOIL_NOP_LENGTH = 10;

    class Recoil : public Cheat {

    public:
        Recoil(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                Cheat(_T("No recoil"), baseAddress, mem, logger),
                pPlayer{ pPlayer } {
            originalRecoilNopBytes = nullptr;
        }

        ~Recoil() override {
            delete[] originalRecoilNopBytes;
        }

        bool toggle(bool enabled) override;

    private:
        playerent* pPlayer;
        BYTE* originalRecoilNopBytes;

    };
}

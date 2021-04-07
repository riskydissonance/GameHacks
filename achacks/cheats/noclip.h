#pragma once

#include <cheat/cheat.h>
#include "../reclass/playerent.h"

namespace cheat {

    class NoClip : public Cheat {

    public:
        NoClip(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                Cheat(_T("No Clip"), baseAddress, mem, logger),
                pPlayer{ pPlayer } {
        }

        ~NoClip() override = default;

        bool toggle(bool enabled) override;

    private:
        playerent* pPlayer;

    };

}

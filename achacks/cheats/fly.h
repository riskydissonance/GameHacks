#pragma once

#include <cheat/cheat.h>
#include "../reclass/playerent.h"

namespace cheat {

    class Fly : public Cheat {

    public:

        Fly(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                Cheat(_T("Fly"), baseAddress, mem, logger),
                pPlayer{ pPlayer } {
        }

        ~Fly() override = default;

        bool toggle(bool enabled) override;

    private:
        playerent* pPlayer;

    };

}

#pragma once

#include <cheat/cheat.h>
#include "../reclass/playerent.h"

namespace cheat {

    class ESP : public Cheat {

    public:

        ESP(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                Cheat(_T("ESP"), baseAddress, mem, logger),
                pPlayer{ pPlayer } {
        }

        ~ESP() override = default;

        bool toggle(bool enabled) override;

    private:
        playerent* pPlayer;

    };

}

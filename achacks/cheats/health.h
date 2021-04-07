#pragma once

#include <cheat/cheat.h>
#include "../reclass/playerent.h"

extern void __cdecl infiniteHealthHook();

namespace cheat {

    class Health : public Cheat {

    public:
        Health(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                Cheat(_T("Infinite Health"), baseAddress, mem, logger),
                pPlayer{ pPlayer } {
            originalHealthHookBytes = nullptr;
        }

        ~Health() override {
            delete[] originalHealthHookBytes;
        }

        bool toggle(bool enabled) override;

    private:
        playerent* pPlayer;
        BYTE* originalHealthHookBytes;

    };
}

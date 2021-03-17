#pragma once

#include "../playerent.h"

extern void __cdecl infiniteHealthHook();

namespace cheats {

    class Health {

    public:
        Health(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                baseAddress{ baseAddress },
                pPlayer{ pPlayer },
                logger{ logger },
                mem{ mem } {
            originalHealthHookBytes = nullptr;
        }

        ~Health() {
            delete[] originalHealthHookBytes;
        }

        bool toggleInfiniteHealth(bool enabled);

    private:
        const uintptr_t baseAddress;
        playerent* pPlayer;
        const mem::Mem& mem;
        const logging::Logger& logger;
        BYTE* originalHealthHookBytes;

    };
}

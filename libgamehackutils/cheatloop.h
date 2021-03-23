#pragma once

#include <list>

namespace cheatloop {

    class CheatLoop {

    public:
        const typedef void (* _cheatLoopFunc)(const uintptr_t& baseAddress, uintptr_t* pPlayer, const mem::Mem& mem, const logging::Logger& logger);

        CheatLoop(const uintptr_t& baseAddress, uintptr_t* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                baseAddress{ baseAddress },
                pPlayer{ pPlayer },
                logger{ logger },
                mem{ mem } {
            cheatLoopFuncs = {};
        }

        ~CheatLoop() = default;

        void registerLoopFunc(_cheatLoopFunc cheatLoopFunc);

        void unregisterLoopFunc(_cheatLoopFunc  cheatLoopFunc);

        void executeLoopFuncs();

    private:
        const uintptr_t baseAddress;
        uintptr_t* pPlayer;
        const mem::Mem& mem;
        const logging::Logger& logger;
        std::list<_cheatLoopFunc> cheatLoopFuncs;

    };


}

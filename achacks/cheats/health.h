#pragma once

#include "../playerent.h"

static void __declspec(naked) infiniteHealthHook(){

    __asm {
        // Original code
        // sub [ebx+0x4], edi
        // mov eax, edi
        cmp [ebx+0xac], 0 // ebx+0xac is number of shots fired which isn't tracked for bots
        jne end
        mov [ebx+0x4], 0 // Set health to 0
        ret
    end:
        ret
    }

}

namespace cheats {


    class Health {

    public:

        Health(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                baseAddress { baseAddress },
                pPlayer { pPlayer },
                logger { logger },
                mem { mem } {
            originalHealthHookBytes = nullptr;
        }

        ~Health(){
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

#pragma once

#include <logging/logger.h>
#include "native/native.h"

namespace mem {

    class Mem {

    public:
        explicit Mem(logging::Logger& logger, native::NativeFunctions& nativeFunctions) :
                logger{ logger },
                nativeFunctions{ nativeFunctions } { };

        ~Mem() = default;

        template<typename T>
        T readMem(uintptr_t targetAddress) const;

        template<typename T>
        T writeMem(uintptr_t targetAddress, T newValue) const;

        bool readMem(uintptr_t targetAddress, size_t length, BYTE* readBytes) const;

        bool writeMem(uintptr_t targetAddress, const BYTE* bytes, size_t length, BYTE* originalBytes) const;

        bool nop(uintptr_t targetAddress, size_t length, BYTE* originalBytes) const;

        /**
        * Patch a function at hookAddress with a jmp to funcAddress, filling extra bytes up to overwriteLength with nops.
         * Saves the original bytes. Uses call by default unless jmpNotCall is true.
        */
        bool hookFunc(uintptr_t hookAddress, uintptr_t funcAddress, BYTE* originalBytes, size_t overwriteLength, const bool jmpNotCall) const;

        /**
         * Patch the hook function after the hook func bytes with the overwritten bytes from the hook and a jump back to the instruction after the original hook.
         */
        bool patchHookFunc(const uintptr_t hookAddress, const uintptr_t funcAddress, const BYTE* originalBytes, const size_t overwriteLength, const bool jmpNotCall, const int hookLength) const;

    private:
        const native::NativeFunctions& nativeFunctions;
        const logging::Logger& logger;
    };


}

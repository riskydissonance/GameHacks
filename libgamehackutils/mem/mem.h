#pragma once

#include "native/native.h"

namespace mem {

    class Mem {

    public:
        explicit Mem(native::NativeFunctions& nativeFunctions) : nativeFunctions{ nativeFunctions } { };

        ~Mem() = default;

        template<typename T>
        T readMem(uintptr_t targetAddress) const;

        template<typename T>
        T writeMem(uintptr_t targetAddress, T newValue) const;

        bool readMem(uintptr_t targetAddress, size_t length, BYTE* readBytes) const;

        bool writeMem(uintptr_t targetAddress, const BYTE* bytes, size_t length, BYTE* originalBytes) const;

        bool nop(uintptr_t targetAddress, size_t length, BYTE* originalBytes) const;

        bool hookFunc(uintptr_t hookAddress, uintptr_t funcAddress, BYTE* originalBytes) const;

    private:
        native::NativeFunctions& nativeFunctions;
    };


}

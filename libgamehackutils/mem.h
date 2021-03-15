#pragma once

#include "native.h"

namespace mem {

    class Mem {

    public:

        explicit Mem(native::NativeFunctions& nativeFunctions);

        ~Mem();

        bool readMem(uintptr_t targetAddress, size_t length, BYTE* originalBytes) const;

        bool writeMem(uintptr_t targetAddress, const BYTE* bytes, size_t length, BYTE* originalBytes) const;

        bool nop(uintptr_t targetAddress, size_t length, BYTE* originalBytes) const;

        bool hookFunc(uintptr_t hookAddress, uintptr_t funcAddress, BYTE* originalBytes) const;

    private:
        native::NativeFunctions& nativeFunctions;
    };


}

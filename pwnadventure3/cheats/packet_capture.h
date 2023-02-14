#pragma once

#include <cheat/cheat.h>

namespace cheat {

    class PacketCapture : public Cheat {

    public:
        PacketCapture(const uintptr_t& baseAddress, const mem::Mem& mem, const logging::Logger& logger) :
                Cheat(_T("Packet Capture"), baseAddress, mem, logger) {
            originalFuncBytes = nullptr;
        }

        ~PacketCapture() override {
            delete[] originalFuncBytes;
        }

        bool toggle(bool enabled) override;

    private:
        BYTE* originalFuncBytes;

    };
}

#pragma once

#include <cheat/cheat.h>

namespace cheat {

    class PacketCapture : public Cheat {

    public:
        PacketCapture(const uintptr_t& baseAddress, const mem::Mem& mem, const logging::Logger& logger) :
                Cheat(_T("Packet Capture"), baseAddress, mem, logger) {
            originalSendFuncBytes = nullptr;
            originalRecvFuncBytes = nullptr;
        }

        ~PacketCapture() override {
            delete[] originalSendFuncBytes;
            delete[] originalRecvFuncBytes;
        }

        bool toggle(bool enabled) override;

    private:
        BYTE* originalSendFuncBytes;
        BYTE* originalRecvFuncBytes;

    };
}

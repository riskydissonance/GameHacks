#pragma once

#include <cheat/cheat.h>
#include <fstream>
#include <iostream>

namespace cheat {

    class PacketCapture : public Cheat {

    public:
        PacketCapture(const uintptr_t& baseAddress, const mem::Mem& mem, const logging::Logger& logger) :
                Cheat(_T("Packet Capture"), baseAddress, mem, logger) {
            originalSendFuncBytes = nullptr;
            originalRecvFuncBytes = nullptr;

            auto gotConsole = AllocConsole();

            if (!gotConsole) {
                logger.debug_log(_T("[-] Could not allocate console"));
                return;
            }
            FILE* f;
            freopen_s(&f, "CONOUT$", "w", stdout);
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

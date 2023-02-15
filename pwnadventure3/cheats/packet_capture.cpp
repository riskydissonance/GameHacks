#include "packet_capture.h"
#include "utils/utils.h"
#include <fstream>
#include <iostream>

std::ofstream out;
static int packet = 0;

void __cdecl displaySocketSend(BYTE buf[], int length) {
    hexdump(packet, out, buf, length);
    packet++;
}

void __declspec(naked) socketSendHook() {
    __asm {
            sub esp, 60h
            pushad
            pushfd
            mov eax, [esp+88h]
            mov ecx, [esp+8ch]
            push ecx
            push eax
            call displaySocketSend
            pop eax
            pop eax
            popfd
            popad
            add esp, 60h
            int3
            int3
            int3
            int3
            int3
            int3
            int3
            int3
            int3
            int3
            int3
            int3
            int3
            int3
            int3
    }
}

bool cheat::PacketCapture::toggle(const bool enabled) {

    auto hGameLogic = GetModuleHandleA("GameLogic.dll");

    const auto hookAddress = (uintptr_t) hGameLogic + SOCKET_SEND_HOOK_OFFSET;
    logger.debug_log(_T("[*] Socket send address: 0x%p"), hookAddress);
    logger.debug_log(_T("[*] PacketCapture Socket Send Hook address at 0x%p"), hookAddress);
    logger.debug_log(_T("[*] PacketCapture Hook function address at 0x%p"), &socketSendHook);

    if (enabled) {
        out = std::ofstream("packets.txt");
        if (!originalFuncBytes) {
            originalFuncBytes = new BYTE[SOCKET_SEND_HOOK_LENGTH]{};
        }

        if (!mem.hookFunc(hookAddress, (uintptr_t) & socketSendHook, originalFuncBytes, SOCKET_SEND_HOOK_LENGTH, true)) {
            logger.debug_log(_T("[-] Unable to set PacketCapture hook"));
            return false;
        }
        logger.debug_log(_T("[+] Set PacketCapture hook"));

        if (!mem.patchHookFunc(hookAddress, (uintptr_t) & socketSendHook, originalFuncBytes, SOCKET_SEND_HOOK_LENGTH, true)) {
            logger.debug_log(_T("[-] Unable to patch hook function"));
            return false;
        }

        logger.debug_log(_T("[+] Patched hook func with return"));
        return true;
    }

    if (originalFuncBytes) {
        return mem.writeMem(hookAddress, originalFuncBytes, SOCKET_SEND_HOOK_LENGTH, nullptr);
    }

    out.close();

    return true;
}

#include "packet_capture.h"


void __declspec(naked) displaySocketSend(uintptr_t thiz, BYTE buf[], int length) {

    __asm {
            int3
            ret
    }

}


void __declspec(naked) socketSendHook() {
    __asm {
            call displaySocketSend
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

    return true;
}

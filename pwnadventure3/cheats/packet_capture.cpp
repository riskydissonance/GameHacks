#include "packet_capture.h"
#include "utils/utils.h"
#include <fstream>
#include <iostream>

std::ofstream out;
static int packet = 0;

void __cdecl handleSocketSend(BYTE buf[], int length) {
    hexdump(packet, 1, out, buf, length);
    if(length == 22 && buf[0] == 'm' && buf[1] == 'v' && buf[2]){
        hexdump(packet, 1, out, buf, length);
        out << std::setw(8) << packet;
        out << ' ';
        out << std::setw(2) << 1;
        out << ' ';
        out << "mv ";
        auto x = (int*)&buf[2];
        auto y = (int*)&buf[6];
        auto z = (int*)&buf[10];
        out << "x: " << *x << " y: " << *y << " z: " << *z;
        out << std::endl;
    }
    packet++;
}

void __cdecl handleSocketRecv(BYTE buf[], int length) {
    hexdump(packet, 2, out, buf, length);
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
            call handleSocketSend
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

void __declspec(naked) socketRecvHook() {
    __asm {
            sub esp, 60h
            pushad
            pushfd
            mov eax, [esp+0x54]
            mov ecx, [esp+0x58]
            push ecx
            push eax
            call handleSocketRecv
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

    const auto sendHookAddress = (uintptr_t) hGameLogic + SOCKET_SEND_HOOK_OFFSET;
    logger.debug_log(_T("[*] Socket send address: 0x%p"), sendHookAddress);
    logger.debug_log(_T("[*] PacketCapture Socket Send Hook address at 0x%p"), sendHookAddress);
    logger.debug_log(_T("[*] PacketCapture send Hook function address at 0x%p"), &socketSendHook);

    const auto recvHookAddress = (uintptr_t) hGameLogic + SOCKET_RECV_HOOK_OFFSET;
    logger.debug_log(_T("[*] Socket recv address: 0x%p"), recvHookAddress);
    logger.debug_log(_T("[*] PacketCapture Socket Recv Hook address at 0x%p"), recvHookAddress);
    logger.debug_log(_T("[*] PacketCapture recv Hook function address at 0x%p"), &socketSendHook);

    if (enabled) {
        out = std::ofstream("packets.txt");

        if (!originalSendFuncBytes) {
            originalSendFuncBytes = new BYTE[SOCKET_SEND_HOOK_LENGTH]{};
        }

        if (!mem.hookFunc(sendHookAddress, (uintptr_t) & socketSendHook, originalSendFuncBytes, SOCKET_SEND_HOOK_LENGTH, true)) {
            logger.debug_log(_T("[-] Unable to set PacketCapture send hook"));
            return false;
        }
        logger.debug_log(_T("[+] Set PacketCapture send hook"));

        if (!mem.patchHookFunc(sendHookAddress, (uintptr_t) & socketSendHook, originalSendFuncBytes, SOCKET_SEND_HOOK_LENGTH, true, SOCKET_SEND_HOOK_FUNC_LENGTH)) {
            logger.debug_log(_T("[-] Unable to patch send hook function"));
            return false;
        }

        logger.debug_log(_T("[+] Patched send hook func with return"));

        if (!originalRecvFuncBytes) {
            originalRecvFuncBytes = new BYTE[SOCKET_RECV_HOOK_LENGTH]{};
        }

        if (!mem.hookFunc(recvHookAddress, (uintptr_t) & socketRecvHook, originalRecvFuncBytes, SOCKET_RECV_HOOK_LENGTH, true)) {
            logger.debug_log(_T("[-] Unable to set PacketCapture recv hook"));
            return false;
        }
        logger.debug_log(_T("[+] Set PacketCapture recv hook"));

        if (!mem.patchHookFunc(recvHookAddress, (uintptr_t) & socketRecvHook, originalRecvFuncBytes, SOCKET_RECV_HOOK_LENGTH, true, SOCKET_RECV_HOOK_FUNC_LENGTH)) {
            logger.debug_log(_T("[-] Unable to patch recv hook function"));
            return false;
        }

        logger.debug_log(_T("[+] Patched recv hook func with return"));

        return true;
    }

    if (originalSendFuncBytes) {
        return mem.writeMem(sendHookAddress, originalSendFuncBytes, SOCKET_SEND_HOOK_LENGTH, nullptr);
    }

    if (originalRecvFuncBytes) {
        return mem.writeMem(recvHookAddress, originalRecvFuncBytes, SOCKET_RECV_HOOK_LENGTH, nullptr);
    }

    out.close();
    return true;
}

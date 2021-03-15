BOOL native::Syscalls::VirtualProtect(_In_  LPVOID lpAddress, _In_  SIZE_T dwSize, _In_  DWORD flNewProtect, _Out_ PDWORD lpFlOldProtect) const {

    // TODO emulate NtProtectVirtualMemory using syscalls directly
    __asm {
        mov eax, 0
    }

}

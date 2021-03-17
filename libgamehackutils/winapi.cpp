BOOL native::WinAPI::VirtualProtect(_In_  LPVOID lpAddress, _In_  SIZE_T dwSize, _In_  DWORD flNewProtect, _Out_
                                    PDWORD lpFlOldProtect) const {
    return ::VirtualProtect(lpAddress, dwSize, flNewProtect, lpFlOldProtect);
}

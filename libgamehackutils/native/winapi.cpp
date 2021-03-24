BOOL native::WinAPI::VirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpFlOldProtect) const {
    return ::VirtualProtect(lpAddress, dwSize, flNewProtect, lpFlOldProtect);
}

HANDLE native::WinAPI::OpenProcess(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId) const {
    return ::OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId);
}

HANDLE native::WinAPI::CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags,
                                    LPDWORD lpThreadId) const {
    return ::CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
}

HANDLE native::WinAPI::CreateRemoteThread(HANDLE hProcess, LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter,
                                          DWORD dwCreationFlags, LPDWORD lpThreadId) const {
    return ::CreateRemoteThread(hProcess, lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
}

BOOL native::WinAPI::ReadProcessMemory(HANDLE hProcess, LPCVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesRead) const {
    return ::ReadProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesRead);
}

LPVOID native::WinAPI::VirtualAllocEx(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect) const {
    return ::VirtualAllocEx(hProcess, lpAddress, dwSize, flAllocationType, flProtect);
}

BOOL native::WinAPI::VirtualProtectEx(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpFlOldProtect) const {
    return ::VirtualProtectEx(hProcess, lpAddress, dwSize, flNewProtect, lpFlOldProtect);
}

BOOL native::WinAPI::WriteProcessMemory(HANDLE hProcess, LPVOID lpBaseAddress, LPCVOID lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesWritten) const {
    return ::WriteProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesWritten);
}

BOOL native::WinAPI::EnumProcessModules(HANDLE hProcess, HMODULE* lphModule, DWORD cb, LPDWORD lpCbNeeded) const {
    return ::EnumProcessModules(hProcess, lphModule, cb, lpCbNeeded);
}

DWORD native::WinAPI::GetModuleBaseName(HANDLE hProcess, HMODULE hModule, LPSTR lpBaseName, DWORD nSize) const {
    return ::GetModuleBaseName(hProcess, hModule, lpBaseName, nSize);
}

BOOL native::WinAPI::EnumProcesses(DWORD* lpIdProcess, DWORD cb, LPDWORD lpCbNeeded) const {
    return ::EnumProcesses(lpIdProcess, cb, lpCbNeeded);
}

BOOL native::WinAPI::QueryFullProcessImageName(HANDLE hProcess, DWORD dwFlags, LPSTR lpExeName, PDWORD lpDwSize) const {
    return ::QueryFullProcessImageName(hProcess, dwFlags, lpExeName, lpDwSize);
}

DWORD native::WinAPI::GetProcessImageFileName(HANDLE hProcess, LPSTR lpImageFileName, DWORD nSize) const {
    return ::GetProcessImageFileName(hProcess, lpImageFileName, nSize);
}

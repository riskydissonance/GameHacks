#include "native.h"

// TODO delegate to syswhispers
BOOL native::Syscalls::VirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpFlOldProtect) const {
    return false;
}

HANDLE native::Syscalls::OpenProcess(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId) const {
    return nullptr;
}

HANDLE
native::Syscalls::CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags,
                               LPDWORD lpThreadId) const {
    return nullptr;
}

HANDLE native::Syscalls::CreateRemoteThread(HANDLE hProcess, LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize,
                                            LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags,
                                            LPDWORD lpThreadId) const {
    return nullptr;
}

BOOL native::Syscalls::ReadProcessMemory(HANDLE hProcess, LPCVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesRead) const {
    return false;
}

LPVOID native::Syscalls::VirtualAllocEx(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect) const {
    return nullptr;
}

BOOL native::Syscalls::VirtualProtectEx(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect) const {
    return false;
}

BOOL native::Syscalls::WriteProcessMemory(HANDLE hProcess, LPVOID lpBaseAddress, LPCVOID lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesWritten) const {
    return false;
}

BOOL native::Syscalls::EnumProcessModules(HANDLE hProcess, HMODULE* lphModule, DWORD cb, LPDWORD lpcbNeeded) const {
    return false;
}

DWORD native::Syscalls::GetModuleBaseName(HANDLE hProcess, HMODULE hModule, LPSTR lpBaseName, DWORD nSize) const {
    return 0;
}

BOOL native::Syscalls::EnumProcesses(DWORD* lpidProcess, DWORD cb, LPDWORD lpcbNeeded) const {
    return false;
}

BOOL native::Syscalls::QueryFullProcessImageName(HANDLE hProcess, DWORD dwFlags, LPSTR lpExeName, PDWORD lpdwSize) const {
    return false;
}

DWORD native::Syscalls::GetProcessImageFileName(HANDLE hProcess, LPSTR lpImageFileName, DWORD nSize) const {
    return 0;
}

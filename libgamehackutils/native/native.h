#pragma once

#include <Windows.h>

namespace native {

    class NativeFunctions {

    public:
        virtual ~NativeFunctions() = default;

        virtual BOOL WINAPI VirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpFlOldProtect) const = 0;

        virtual HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId) const = 0;

        virtual HANDLE CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress,
                                    __drv_aliasesMem LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId) const = 0;

        virtual HANDLE CreateRemoteThread(HANDLE hProcess, LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize,
                                          LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId) const = 0;

        virtual LPVOID VirtualAllocEx(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect) const = 0;

        virtual BOOL VirtualProtectEx(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect) const = 0;

        virtual BOOL ReadProcessMemory(HANDLE hProcess, LPCVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesRead) const = 0;

        virtual BOOL WriteProcessMemory(HANDLE hProcess, LPVOID lpBaseAddress, LPCVOID lpBuffer, SIZE_T nSize,
                                        SIZE_T* lpNumberOfBytesWritten) const = 0;

        virtual BOOL EnumProcessModules(HANDLE hProcess, HMODULE* lphModule, DWORD cb, LPDWORD lpcbNeeded) const = 0;

        virtual DWORD GetModuleBaseName(HANDLE hProcess, HMODULE hModule, LPSTR lpBaseName, DWORD nSize) const = 0;

        virtual BOOL EnumProcesses(DWORD* lpidProcess, DWORD cb, LPDWORD lpcbNeeded) const = 0;

        virtual BOOL QueryFullProcessImageName(HANDLE hProcess, DWORD dwFlags, LPSTR lpExeName, PDWORD lpdwSize) const = 0;

        virtual DWORD GetProcessImageFileName(HANDLE hProcess, LPSTR lpImageFileName, DWORD nSize) const = 0;
    };

    class WinAPI : public NativeFunctions {

    public:
        WinAPI() = default;

        ~WinAPI() override = default;

        BOOL WINAPI VirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpFlOldProtect) const override;


        HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId) const override;

        HANDLE CreateRemoteThread(HANDLE hProcess, LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize,
                                  LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId) const override;

        HANDLE CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress,
                            __drv_aliasesMem LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId) const override;

        LPVOID VirtualAllocEx(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect) const override;

        BOOL VirtualProtectEx(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect) const override;

        BOOL ReadProcessMemory(HANDLE hProcess, LPCVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesRead) const override;

        BOOL WriteProcessMemory(HANDLE hProcess, LPVOID lpBaseAddress, LPCVOID lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesWritten) const override;

        BOOL EnumProcessModules(HANDLE hProcess, HMODULE* lphModule, DWORD cb, LPDWORD lpcbNeeded) const override;

        DWORD GetModuleBaseName(HANDLE hProcess, HMODULE hModule, LPSTR lpBaseName, DWORD nSize) const override;

        BOOL EnumProcesses(DWORD* lpidProcess, DWORD cb, LPDWORD lpcbNeeded) const override;

        BOOL QueryFullProcessImageName(HANDLE hProcess, DWORD dwFlags, LPSTR lpExeName, PDWORD lpdwSize) const override;

        DWORD GetProcessImageFileName(HANDLE hProcess, LPSTR lpImageFileName, DWORD nSize) const override;
    };

    class Syscalls : public NativeFunctions {

    public:
        Syscalls() = default;

        ~Syscalls() override = default;

        BOOL WINAPI VirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpFlOldProtect) const override;

        HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwProcessId) const override;

        HANDLE CreateRemoteThread(HANDLE hProcess, LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize,
                                  LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId) const override;

        HANDLE CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress,
                            __drv_aliasesMem LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId) const override;

        LPVOID VirtualAllocEx(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect) const override;

        BOOL VirtualProtectEx(HANDLE hProcess, LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect) const override;

        BOOL ReadProcessMemory(HANDLE hProcess, LPCVOID lpBaseAddress, LPVOID lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesRead) const override;

        BOOL WriteProcessMemory(HANDLE hProcess, LPVOID lpBaseAddress, LPCVOID lpBuffer, SIZE_T nSize, SIZE_T* lpNumberOfBytesWritten) const override;

        BOOL EnumProcessModules(HANDLE hProcess, HMODULE* lphModule, DWORD cb, LPDWORD lpcbNeeded) const override;

        DWORD GetModuleBaseName(HANDLE hProcess, HMODULE hModule, LPSTR lpBaseName, DWORD nSize) const override;

        BOOL EnumProcesses(DWORD* lpidProcess, DWORD cb, LPDWORD lpcbNeeded) const override;

        BOOL QueryFullProcessImageName(HANDLE hProcess, DWORD dwFlags, LPSTR lpExeName, PDWORD lpdwSize) const override;

        DWORD GetProcessImageFileName(HANDLE hProcess, LPSTR lpImageFileName, DWORD nSize) const override;
    };
}

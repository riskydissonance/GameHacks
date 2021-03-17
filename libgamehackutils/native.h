#pragma once

#include <Windows.h>

namespace native {

    class NativeFunctions {

    public:
        virtual ~NativeFunctions() = default;

        virtual BOOL WINAPI VirtualProtect(_In_  LPVOID lpAddress, _In_  SIZE_T dwSize, _In_  DWORD flNewProtect, _Out_
                                           PDWORD lpFlOldProtect) const = 0;

    };

    class WinAPI : public NativeFunctions {

    public:

        WinAPI() = default;

        ~WinAPI() override = default;

        BOOL WINAPI VirtualProtect(_In_  LPVOID lpAddress, _In_  SIZE_T dwSize, _In_  DWORD flNewProtect, _Out_
                                   PDWORD lpFlOldProtect) const override;

    };

    class Syscalls : public NativeFunctions {

    public:

        Syscalls() = default;

        ~Syscalls() override = default;

        BOOL WINAPI VirtualProtect(_In_  LPVOID lpAddress, _In_  SIZE_T dwSize, _In_  DWORD flNewProtect, _Out_
                                   PDWORD lpFlOldProtect) const override;

    };
}

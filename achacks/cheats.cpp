#include "cheats.h"
#include "playerent.h"
#include <tchar.h>

BYTE* originalAmmoDecrementBytes;
BYTE* originalGrenadeDecrementBytes;

bool toggleInfiniteAmmo(const bool enabled, const uintptr_t baseAddress, const mem::Mem& mem, const logging::Logger& logger) {

    const auto ammoDecrementAddress = baseAddress + 0x637e9;
    logger.debug_log(_T("[*] Ammo decrement address at 0x%x"), ammoDecrementAddress);

    const auto grenadeDecrementAddress = baseAddress + 0x63378;
    logger.debug_log(_T("[*] Grenade decrement address at 0x%x"), grenadeDecrementAddress);

    bool totalSuccess = true;

    if(enabled)
    {
        if (!originalAmmoDecrementBytes)
        {
            originalAmmoDecrementBytes = new BYTE[NEAR_JMP_INSTRUCTION_LENGTH]{};
        }

        if (mem.nop(ammoDecrementAddress, 2, originalAmmoDecrementBytes))
        {
            logger.debug_log(_T("[+] Set Infinite Ammo by NOPing decrement"));
        }
        else
        {
            logger.debug_log(_T("[-] Unable to set Infinite Ammo by NOPing decrement"));
            totalSuccess = false;
        }

        if (!originalGrenadeDecrementBytes)
        {
            originalGrenadeDecrementBytes = new BYTE[NEAR_JMP_INSTRUCTION_LENGTH]{};
        }

        if (mem.nop(grenadeDecrementAddress, 2, originalGrenadeDecrementBytes))
        {
            logger.debug_log(_T("[+] Set Infinite Grenades by NOPing decrement"));
            return totalSuccess;
        }

        logger.debug_log(_T("[-] Unable to set Infinite Grenades by NOPing decrement"));
        return false;
    }

    if (originalAmmoDecrementBytes)
    {
        totalSuccess =  totalSuccess && mem.writeMem(ammoDecrementAddress, originalAmmoDecrementBytes, NEAR_JMP_INSTRUCTION_LENGTH, nullptr);
    }

    if (originalGrenadeDecrementBytes)
    {
        totalSuccess =  totalSuccess && mem.writeMem(grenadeDecrementAddress, originalGrenadeDecrementBytes, NEAR_JMP_INSTRUCTION_LENGTH, nullptr);
    }

    return totalSuccess;
}

void __declspec(naked) infiniteHealthHook(){

    __asm {
        cmp [ebx+0xac], 0 // ebx+0xac is number of shots fired which isn't tracked for bots
        jne end
        sub [ebx+0x4], edi // Subtract from health
    end:
        mov eax, edi
        ret
    }

}

BYTE* originalHealthHookBytes;

bool toggleInfiniteHealth(const bool enabled, const uintptr_t baseAddress, const mem::Mem& mem, const logging::Logger& logger) {

    const auto hookAddress = baseAddress + 0x29d1f;

    logger.debug_log(_T("[*] Infinite Health Hook address at 0x%x"), hookAddress);
    logger.debug_log(_T("[*] Infinite Health Hook function address at 0x%x"), &infiniteHealthHook);

    if(enabled)
    {
        if (!originalHealthHookBytes)
        {
            originalHealthHookBytes = new BYTE[NEAR_JMP_INSTRUCTION_LENGTH]{};
        }

        if (mem.hookFunc(hookAddress, (uintptr_t) &infiniteHealthHook, originalHealthHookBytes))
        {
            logger.debug_log(_T("[+] Set Infinite Health hook"));
            return true;
        }

        logger.debug_log(_T("[-] Unable to set Infinite Health hook"));
        return false;
    }

    if (originalHealthHookBytes)
    {
        return mem.writeMem(hookAddress, originalHealthHookBytes, NEAR_JMP_INSTRUCTION_LENGTH, nullptr);
    }

    return true;
}

void __stdcall injectCheats(const HMODULE hModule) {

    logging::Logger* logger = new logging::DebugLogger{};
    native::NativeFunctions* nativeFunctions = new native::WinAPI{};
    auto mem = new mem::Mem{ *nativeFunctions };

    uintptr_t baseAddress;

    __asm {
        // Get module base address via TEB+0x30 -> PEB+0x8 -> base address
        mov eax, dword ptr fs:[0x30]
        mov eax, dword ptr ds:[eax+0x8]
        mov baseAddress, eax
    }

    logger->debug_log(_T("[*] Main module base address at 0x%x, 0x%p"), baseAddress, baseAddress);

    const auto playerAddress = (uintptr_t*)(baseAddress + 0x10F4F4);
    logger->debug_log(_T("[*] Player at: 0x%x"), playerAddress);

    auto pPlayer = reinterpret_cast<playerent*>(*playerAddress);

    auto cheatsEnabled = false;

    while(true){

        if(GetAsyncKeyState(VK_INSERT) & 0x01){
            cheatsEnabled = !cheatsEnabled;

            if(cheatsEnabled)
            {
                pPlayer->Health = 1337;
                logger->debug_log(_T("[+] Set health to 1337"));

                pPlayer->PrimaryAmmo = 1337;
                logger->debug_log(_T("[+] Set ammo to 1337"));
            }

            toggleInfiniteHealth(cheatsEnabled, baseAddress, *mem, *logger);
            toggleInfiniteAmmo(cheatsEnabled, baseAddress, *mem, *logger);
        }

        if (GetAsyncKeyState(VK_END) & 0x01) {
            toggleInfiniteHealth(false, baseAddress, *mem, *logger);
            break;
        }

        Sleep(100);
    }

    delete[] originalAmmoDecrementBytes;
    delete[] originalHealthHookBytes;
    delete[] originalGrenadeDecrementBytes;
    delete mem;
    delete nativeFunctions;
    logger->debug_log(_T("[*] Exiting"));
    delete logger;
    FreeLibraryAndExitThread(hModule, 0);
}

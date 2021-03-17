#include "health.h"

bool cheats::Health::toggleInfiniteHealth(const bool enabled) {

    const auto hookAddress = baseAddress + 0x29d1f;

    logger.debug_log(_T("[*] Infinite Health Hook address at 0x%x"), hookAddress);
    logger.debug_log(_T("[*] Infinite Health Hook function address at 0x%x"), &infiniteHealthHook);

    if(enabled)
    {
        pPlayer->Health = 1337;
        pPlayer->Armour = 1337;
        logger.debug_log(_T("[+] Set health and armour to 1337"));

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

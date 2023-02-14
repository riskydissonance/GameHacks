#include "health.h"

bool cheat::Health::toggle(const bool enabled) {

    const auto hookAddress = baseAddress + HEALTH_HOOK_OFFSET;

    logger.debug_log(_T("[*] Infinite Health Hook address at 0x%p"), hookAddress);
    logger.debug_log(_T("[*] Infinite Health Hook function address at 0x%p"), &infiniteHealthHook);

    if (enabled) {
        pPlayer->Health = 1337;
        pPlayer->Armour = 1337;
        logger.debug_log(_T("[+] Set health and armour to 1337"));

        if (!originalFuncBytes) {
            originalFuncBytes = new BYTE[HEALTH_HOOK_LENGTH]{};
        }

        if (mem.hookFunc(hookAddress, (uintptr_t) &infiniteHealthHook, originalFuncBytes, HEALTH_HOOK_LENGTH, false)) {
            logger.debug_log(_T("[+] Set Infinite Health hook"));
            return true;
        }

        logger.debug_log(_T("[-] Unable to set Infinite Health hook"));
        return false;
    }

    if (originalFuncBytes) {
        return mem.writeMem(hookAddress, originalFuncBytes, HEALTH_HOOK_LENGTH, nullptr);
    }

    return true;
}

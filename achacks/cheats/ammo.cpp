#include "ammo.h"

bool cheats::Ammo::toggleInfiniteAmmo(const bool enabled) {

    const auto ammoDecrementAddress = baseAddress + 0x637e9;
    logger.debug_log(_T("[*] Ammo decrement address at 0x%x"), ammoDecrementAddress);

    const auto grenadeDecrementAddress = baseAddress + 0x63378;
    logger.debug_log(_T("[*] Grenade decrement address at 0x%x"), grenadeDecrementAddress);

    bool totalSuccess = true;

    if(enabled)
    {

        pPlayer->PrimaryAmmo = 1337;
        pPlayer->SecondaryAmmo = 1337;
        pPlayer->PrimaryAmmoReserve = 1337;
        pPlayer->SecondaryAmmoReserve = 1337;
        pPlayer->AkimboAmmo = 1337;
        pPlayer->AkimboAmmoReserve = 1337;
        pPlayer->NumberOfGrenades = 1337;
        pPlayer->Akimbo = 1;

        logger.debug_log(_T("[+] Set ammo & grenades to 1337"));

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
        totalSuccess =  mem.writeMem(ammoDecrementAddress, originalAmmoDecrementBytes, NEAR_JMP_INSTRUCTION_LENGTH, nullptr);
    }

    if (originalGrenadeDecrementBytes)
    {
        totalSuccess =  totalSuccess && mem.writeMem(grenadeDecrementAddress, originalGrenadeDecrementBytes, NEAR_JMP_INSTRUCTION_LENGTH, nullptr);
    }

    return totalSuccess;
}

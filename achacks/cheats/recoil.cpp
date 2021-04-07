#include "recoil.h"

bool cheat::Recoil::toggle(const bool enabled) {

    if (enabled) {
        originalRecoilNopBytes = new BYTE[RECOIL_NOP_LENGTH];
        logger.debug_log(_T("[*] Nopping recoil function call"));
        return mem.nop(baseAddress + RECOIL_NOP_OFFSET, RECOIL_NOP_LENGTH, originalRecoilNopBytes);
    } else {
        if (originalRecoilNopBytes) {
            logger.debug_log(_T("[*] Rewriting original bytes to recoil function call"));
            return mem.writeMem(baseAddress + RECOIL_NOP_OFFSET, originalRecoilNopBytes, RECOIL_NOP_LENGTH, nullptr);
        }
        return true;
    }

}

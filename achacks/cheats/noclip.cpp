#include "noclip.h"

bool cheat::NoClip::toggle(bool enabled) {

    if (enabled) {
        pPlayer->PlayerState = 4; // No clip
        logger.debug_log(_T("[+] Set no clip"));
    } else {
        pPlayer->PlayerState = 0; // Default
        logger.debug_log(_T("[+] Unset no clip"));
    }

    return true;
}

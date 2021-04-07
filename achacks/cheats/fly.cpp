#include "fly.h"

bool cheat::Fly::toggle(const bool enabled) {

    if (enabled) {
        pPlayer->Fly = 5;
        logger.debug_log(_T("[+] Fly enabled"));
    } else {
        pPlayer->Fly = 0;
        logger.debug_log(_T("[+] Fly disabled"));
    }

    return true;
}

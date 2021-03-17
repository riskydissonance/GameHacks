#include "movement.h"

bool cheats::Movement::toggleFly(bool enabled) {

    if(enabled){
        pPlayer->Fly = 5;
        logger.debug_log(_T("[+] Fly enabled"));
    } else {
        pPlayer->Fly = 0;
        logger.debug_log(_T("[+] Fly disabled"));
    }

    return true;
}

bool cheats::Movement::toggleNoClip(bool enabled) {

    if(enabled){
        pPlayer->PlayerState = 4; // No clip
        logger.debug_log(_T("[+] Set no clip"));
    } else {
        pPlayer->PlayerState = 0; // Default
        logger.debug_log(_T("[+] Unset no clip"));
    }

    return true;
}

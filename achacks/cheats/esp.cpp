#include "esp.h"

bool cheat::ESP::toggle(const bool enabled) {

    if (enabled) {
        logger.debug_log(_T("[+] ESP enabled"));
    } else {
        logger.debug_log(_T("[+] ESP disabled"));
    }

    return true;
}

#include "radar.h"

bool cheat::RadarESP::toggle(const bool enabled) {

    const static auto radarNopAddress = baseAddress + RADAR_NOP_OFFSET;

    if (enabled) {

        if (!originalRadarNopBytes) {
            originalRadarNopBytes = new BYTE[NOP_LENGTH]{};
        }

        if (mem.nop(radarNopAddress, NOP_LENGTH, originalRadarNopBytes)) {
            logger.debug_log(_T("[+] Enabled Radar ESP by NOPing team check"));
            return true;
        } else {
            logger.debug_log(_T("[-] Unable to set Radar ESP by NOPing team check"));
            return false;
        }
    }

    if (originalRadarNopBytes) {
        return mem.writeMem(radarNopAddress, originalRadarNopBytes, NOP_LENGTH, nullptr);
    }
    return true;

}

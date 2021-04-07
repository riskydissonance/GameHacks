#include "triggerbot.h"

bool cheats::states::TriggerBotState::condition() {
    lastTracelineResult = traceline();
    if (lastTracelineResult) {
        return false;
    }
    return true;
}

bool cheats::states::TriggerBotState::reach() {
    if (lastTracelineResult) {
        if (!lastStateWasFiring && lastTracelineResult->Team != pPlayer->Team) {
            pPlayer->Firing = 1;
            lastStateWasFiring = true;
        }
    }
    return true;
}

bool cheats::states::TriggerBotState::reached() {
    if (lastStateWasFiring) {
        pPlayer->Firing = 0;
        lastStateWasFiring = false;
    }
    return true;
}

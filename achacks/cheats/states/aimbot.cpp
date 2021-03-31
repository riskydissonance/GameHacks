#include "aimbot.h"
#include "../../constants.h"
#include <maths/geometry.h>

/*
 * y -90 -> +90
 * x 0 -> 360
 *
 */

bool cheats::states::AimBotState::condition() {

    float closestDistance{};
    int closestIndex = -1;

    for (int i = 1; i <= 1; i++) { // TODO how to determine end of ent list

        auto pEnt = *(entityList + i);
        if (!pEnt)
            break;
        if (pEnt == pPlayer ||
            pEnt->Team == pPlayer->Team ||
            pEnt->Health < 1 ||
            pPlayer->Health < 1)
            continue;

        float distance = getDistance(LimitedVector3{ pEnt->HeadPosition.x, pEnt->HeadPosition.y, pEnt->HeadPosition.z },
                                     LimitedVector3{ pPlayer->HeadPosition.x, pPlayer->HeadPosition.y, pPlayer->HeadPosition.z });


        if (closestDistance == 0 || distance < closestDistance) {
            closestDistance = distance;
            closestIndex = i;
        }
    }

    if (closestIndex == -1)
        return true;

    auto pClosestEnt = *(entityList + closestIndex);

    facingToNearestEnemy = getFacingToVector(LimitedVector3{ pClosestEnt->HeadPosition.x, pClosestEnt->HeadPosition.y, pClosestEnt->HeadPosition.z },
                                             LimitedVector3{ pPlayer->HeadPosition.x, pPlayer->HeadPosition.y, pPlayer->HeadPosition.z });

    if (LimitedVector3{ pPlayer->Facing.x, pPlayer->Facing.y, pPlayer->Facing.z } == facingToNearestEnemy) {
        return true;
    }

    return false;
}

bool cheats::states::AimBotState::reach() {
    this->pPlayer->Facing = facingToNearestEnemy.toVector3();
    return true;
}

bool cheats::states::AimBotState::reached() {
    return true;
}


bool cheats::states::AimBot::toggleAimBot(bool enabled) {
    if (enabled) {
        aimBotState = new AimBotState(baseAddress, pPlayer, mem, logger);
        stateMachine.registerState(aimBotState);
    } else {
        stateMachine.unregisterState(aimBotState);
        delete aimBotState;
    }
    return true;
}

#include "aimbot.h"
#include <maths/geometry.h>

/*
 * y -90 -> +90
 * x 0 -> 360
 *
 */
bool cheats::states::AimBotState::condition() {

    if(!entityList){
        entityList = (playerent**) *pEntList;
        return true;
    }

    if(!(GetAsyncKeyState(VK_LBUTTON) & 01000'0000)){ // Is mouse left click held down
        return true;
    }

    float closestDistance{}; // TODO should also check if visible
    int closestIndex = -1;
    int* pOtherEntitiesCount = (int*)(baseAddress + OTHER_ENTS_COUNT_OFFSET);

    for (int i = 1; i <= *pOtherEntitiesCount; i++) {

        auto pEnt = *(entityList + i);
        if (!pEnt ||
            pEnt == pPlayer ||
            pEnt->Team == pPlayer->Team ||
            pEnt->PlayerState != 0||
            pPlayer->PlayerState != 0)
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

    facingToNearestEnemy.x += 270;

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

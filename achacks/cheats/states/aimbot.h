#pragma once

#include <state/state.h>
#include <state/statemachine.h>
#include "../../reclass/playerent.h"

namespace cheats::states {

    class AimBotState : public state::State {

    public:

        AimBotState(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                State(_T("AimBot")),
                baseAddress{ baseAddress },
                pPlayer{ pPlayer },
                logger{ logger },
                mem{ mem } {
            pEntList = (uintptr_t*) (baseAddress + ENTITY_LIST_OFFSET);
            entityList = (playerent**) *pEntList;
            logger.debug_log("[*] Ent list at 0x%p", *pEntList);
        }

        ~AimBotState() override = default;

        [[nodiscard]] bool condition() override;

        bool reach() override;

        bool reached() override;


    private:
        const uintptr_t baseAddress;
        playerent* pPlayer;
        const mem::Mem& mem;
        const logging::Logger& logger;
        LimitedVector3 facingToNearestEnemy{};
        uintptr_t * pEntList;
        playerent** entityList;

    };

}

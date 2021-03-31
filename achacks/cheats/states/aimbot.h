#pragma once

#include <state/state.h>
#include <state/statemachine.h>
#include "../../reclass/playerent.h"

namespace cheats::states {

    class AimBotState : public state::State {

    public:

        AimBotState(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem,
                    const logging::Logger& logger) : State(_T("AimBot")),
                                                     baseAddress{ baseAddress },
                                                     pPlayer{ pPlayer },
                                                     logger{ logger },
                                                     mem{ mem } {
            auto pEntList = (uintptr_t*) (baseAddress + ENTITY_LIST_OFFSET);
            entityList = (playerent**) *pEntList;
            logger.debug_log("[*] Ent list at 0x%p", *pEntList);
        }

        ~AimBotState() = default;

        [[nodiscard]] bool condition() override;

        bool reach() override;

        bool reached() override;


    private:
        const uintptr_t baseAddress;
        playerent* pPlayer;
        const mem::Mem& mem;
        const logging::Logger& logger;
        LimitedVector3 facingToNearestEnemy{};
        playerent** entityList;

    };

    class AimBot {

    public:

        AimBot(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger,
               state::StateMachine& stateMachine) :
                baseAddress{ baseAddress },
                pPlayer{ pPlayer },
                logger{ logger },
                mem{ mem },
                stateMachine{ stateMachine } {
        }

        ~AimBot() = default;

        bool toggleAimBot(bool enabled);

    private:
        const uintptr_t baseAddress;
        playerent* pPlayer;
        const mem::Mem& mem;
        const logging::Logger& logger;
        state::StateMachine& stateMachine;
        AimBotState* aimBotState;
    };

}

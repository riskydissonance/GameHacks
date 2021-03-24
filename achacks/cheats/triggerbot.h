#pragma once

#include "../reclass/playerent.h"
#include <list>
#include <state/statemachine.h>
#include <state/state.h>

namespace cheats {

    class TriggerBotState : public state::State {

    public:

        typedef playerent* (__cdecl* _traceline)();
        typedef void (__cdecl* _fireWeapon)(bool firing);

        TriggerBotState(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                baseAddress{ baseAddress },
                pPlayer{ pPlayer },
                logger{ logger },
                mem{ mem },
                name{ _T("TriggerBot") } {
            traceline = (_traceline) (baseAddress + TRACELINE_FUNC_OFFSET);
            fireWeapon = (_fireWeapon) (baseAddress + FIRE_WEAPON_OFFSET);
            lastTracelineResult = nullptr;
            wasFiring = false;
        }

        ~TriggerBotState() override = default;

        [[nodiscard]] bool condition() override;

        bool reach() override;

        bool reached() override;

        [[nodiscard]] const TCHAR* getName() const override;

    private:
        const TCHAR* name;
        const uintptr_t baseAddress{};
        playerent* pPlayer;
        const mem::Mem& mem;
        const logging::Logger& logger;
        playerent* lastTracelineResult;
        _traceline traceline;
        _fireWeapon fireWeapon;
        bool wasFiring;

    };

    class TriggerBot {

    public:

        TriggerBot(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger,
                   state::StateMachine& stateMachine) :
                baseAddress{ baseAddress },
                pPlayer{ pPlayer },
                logger{ logger },
                mem{ mem },
                stateMachine{ stateMachine } {
            triggerBotState = new TriggerBotState(baseAddress, pPlayer, mem, logger);

        }

        ~TriggerBot() {
            toggleTriggerBot(false);
            delete triggerBotState;
        }

        bool toggleTriggerBot(bool enabled);

    private:
        const uintptr_t baseAddress;
        playerent* pPlayer;
        const mem::Mem& mem;
        const logging::Logger& logger;
        state::StateMachine& stateMachine;
        state::State* triggerBotState;

    };

}

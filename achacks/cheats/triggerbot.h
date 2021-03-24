#pragma once

#include "../reclass/playerent.h"
#include <list>
#include <state/statemachine.h>
#include <state/state.h>

namespace cheats {

    class TriggerBotState : public state::State {

    public:

        TriggerBotState(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger) :
                baseAddress{ baseAddress },
                pPlayer{ pPlayer },
                logger{ logger },
                mem{ mem },
                name{ _T("TriggerBot") } {
        }

        ~TriggerBotState() override = default;

        [[nodiscard]] bool condition() const override;

        bool reach() override;

        [[nodiscard]] const TCHAR* get_name() const override;

    private:
        const TCHAR* name;
        const uintptr_t baseAddress{};
        playerent* pPlayer;
        const mem::Mem& mem;
        const logging::Logger& logger;

    };

    class TriggerBot {

    public:


        const typedef playerent* (__cdecl* _traceline)();

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

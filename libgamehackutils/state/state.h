#pragma once

namespace state {

    class State {

    public:

        virtual ~State() = default;

        [[nodiscard]] virtual bool condition() = 0;

        virtual bool reach() = 0;

        virtual bool reached() = 0;

        [[nodiscard]] virtual const TCHAR* getName() const = 0;

    };

}

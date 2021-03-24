#pragma once

namespace state {

    class State {

    public:

        virtual ~State() = default;

        [[nodiscard]] virtual bool condition() = 0;

        virtual bool reach() = 0;

        [[nodiscard]] virtual const TCHAR* get_name() const = 0;

    };

}

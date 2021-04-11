#pragma once

namespace state {

    class State {

    public:

        explicit State(const TCHAR* name) : name{ name } { };

        virtual ~State() = default;

        [[nodiscard]] virtual bool condition() = 0;

        virtual bool reach() = 0;

        virtual bool reached() = 0;

        [[nodiscard]] const TCHAR* getName() const {
            return name;
        }

    private:
        const TCHAR* name;

    };

}

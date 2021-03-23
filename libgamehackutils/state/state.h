#pragma once

namespace state {

    class State {

    public:

        virtual ~State() = default;

        virtual bool condition() const = 0;

        virtual bool reach() = 0;

        virtual const TCHAR* get_name() const = 0;

    };

}

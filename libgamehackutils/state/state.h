#pragma once

namespace state {

    class State {

    public:

        virtual ~State() = 0;

        virtual bool condition() const = 0;

        virtual bool reach() = 0;

        virtual TCHAR* get_name() = 0;

    };

}

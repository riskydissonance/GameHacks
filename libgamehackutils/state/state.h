#pragma once

namespace state {

    class State {

    public:

        State(const TCHAR* name) : name { name }{};

        ~State() {
            // TODO why does it error with Exception 0x80000003
            //delete name;
        };

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

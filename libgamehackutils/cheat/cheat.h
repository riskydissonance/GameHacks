#pragma once

namespace cheat {

    class Cheat {

    public:

        Cheat(const TCHAR* name, const uintptr_t& baseAddress, const mem::Mem& mem, const logging::Logger& logger) :
                name{ name },
                baseAddress{ baseAddress },
                logger{ logger },
                mem{ mem } { }

        virtual ~Cheat() = default;

        const uintptr_t baseAddress;
        const mem::Mem& mem;
        const logging::Logger& logger;

        virtual bool toggle(bool enabled) = 0;

        [[nodiscard]] const TCHAR* getName() const {
            return name;
        }

    private:
        const TCHAR* name;

    };

}

#pragma once

namespace logging {

    class Logger {

    public:
        virtual ~Logger() = default;

        virtual void debug_log(const TCHAR* formatString, ...) const = 0;

    };

    class DebugLogger : public Logger {

    public:
        DebugLogger() = default;

        ~DebugLogger() override = default;

        void debug_log(const TCHAR* formatString, ...) const override;
    };
}

void logging::DebugLogger::debug_log(const TCHAR* formatString, ...) const {
    TCHAR message[1025];
    va_list args;
            va_start(args, formatString);
    wvsprintf(message, formatString, args);
            va_end(args);

    TCHAR prefixedMessage[1025];
    wsprintf(prefixedMessage, _T("[%s] %s\n"), CHEAT_NAME, message);

    OutputDebugString(prefixedMessage);
}

void logging::DebugLogger::info_log(const TCHAR* formatString, ...) const {
    va_list args;
            va_start(args, formatString);
    debug_log(formatString, args);
            va_end(args);
}

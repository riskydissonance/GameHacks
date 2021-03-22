void logging::DebugLogger::debug_log(const TCHAR* formatString, ...) const {
    TCHAR prefixedFormatString[1025];
    wsprintf(prefixedFormatString, _T("[%s] %s"), CHEAT_NAME, formatString);

    TCHAR message[1025];
    va_list args;
            va_start(args, prefixedFormatString);
    wvsprintf(message, prefixedFormatString, args);
            va_end(args);
    OutputDebugString(message);
}

void logging::DebugLogger::info_log(const TCHAR* formatString, ...) const {
    va_list args;
            va_start(args, formatString);
    debug_log(formatString, args);
            va_end(args);
}

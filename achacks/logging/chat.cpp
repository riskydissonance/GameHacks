#include "chat.h"

void logging::ACChatLogger::debug_log(const TCHAR* formatString, ...) const {
    TCHAR message[1025];
    va_list args;
            va_start (args, formatString);
    wvsprintf(message, formatString, args);
    debugLogger->debug_log(message);
            va_end(args);

}

void logging::ACChatLogger::info_log(const TCHAR* formatString, ...) const {
#ifdef UNICODE
    chatLog("Widechar Chat logger not supported", "");
#else
    va_list args;
            va_start (args, formatString);
    chatLog((char*) formatString, args);
            va_end(args);
#endif
}

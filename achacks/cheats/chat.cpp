#include "chat.h"

void logging::ChatLogger::debug_log(const TCHAR* formatString, ...) const {

#ifdef UNICODE
    chatLog("Widechar Chat logger not supported", "");
#else
    va_list args;
            va_start (args, formatString);
    chatLog((char*) formatString, args);
            va_end(args);
#endif

}

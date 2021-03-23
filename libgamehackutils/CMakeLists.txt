set(sources
        constants.h
        framework.h
        logging/logger.cpp
        logging/logger.h
        mem/mem.cpp
        mem/mem.h
        native/native.h
        native/syscalls.cpp
        native/winapi.cpp
        anti_re/anti_re.h
        state/cheatloop.cpp
        state/cheatloop.h
        state/statemachine.cpp
        state/statemachine.h
        state/state.h)

add_library(libgamehackutils STATIC
        ${sources}
        )

target_include_directories(libgamehackutils PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_precompile_headers(libgamehackutils PRIVATE pch.h)

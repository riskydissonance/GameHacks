set(sources
        constants.h
        framework.h
        logger.cpp
        logger.h
        mem.cpp
        mem.h
        native.h
        syscalls.cpp
        winapi.cpp
        pch.cpp
        )

add_library(libgamehackutils STATIC
        ${sources}
        )

target_include_directories(libgamehackutils PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_precompile_headers(libgamehackutils PRIVATE pch.h)

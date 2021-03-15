set(sources
        dllmain.cpp
        cheats.cpp
        cheats.h
        framework.h
        pch.cpp
        playerent.h
        )

add_library(achacks SHARED
        ${sources}
        )

target_link_libraries(achacks
        libgamehackutils
        )

target_precompile_headers(achacks PRIVATE pch.h)

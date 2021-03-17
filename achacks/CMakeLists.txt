set(sources
        dllmain.cpp
        cheats.cpp
        cheats.h
        framework.h
        pch.cpp
        playerent.h
        cheats/health.cpp
        cheats/health.h
        cheats/ammo.cpp
        cheats/ammo.h
        cheats/recoil.cpp
        cheats/recoil.h
        cheats/movement.cpp
        cheats/movement.h)

add_library(achacks SHARED
        ${sources}
        )

target_link_libraries(achacks
        libgamehackutils
        )

target_precompile_headers(achacks PRIVATE pch.h)

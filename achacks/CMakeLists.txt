enable_language(ASM_NASM)

set(asm_sources
        cheats/health_hook_x86.asm
        )

set(sources
        ${asm_sources}
        dllmain.cpp
        cheats.cpp
        cheats.h
        offsets.h
        framework.h
        reclass/playerent.h
        cheats/health.cpp
        cheats/health.h
        cheats/ammo.cpp
        cheats/ammo.h
        cheats/recoil.cpp
        cheats/recoil.h
        cheats/fly.cpp
        cheats/fly.h
        cheats/noclip.cpp
        cheats/noclip.h
        logging/chat.cpp
        logging/chat.h
        cheats/states/triggerbot.cpp
        cheats/states/triggerbot.h
        cheats/radar.cpp
        cheats/radar.h
        cheats/states/aimbot.cpp
        cheats/states/aimbot.h cheats/esp.cpp cheats/esp.h)

set_source_files_properties(${asm_sources} PROPERTIES LANGUAGE ASM_NASM)

add_library(achacks SHARED
        ${sources}
        )

target_link_libraries(achacks
        libgamehackutils
        )

target_precompile_headers(achacks PRIVATE pch.h)

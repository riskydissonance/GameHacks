enable_language(ASM_NASM)

if(CMAKE_ARCH STREQUAL "x64")

    set(asm_sources
            )

else()

    set(asm_sources
            get_base_address_x86.asm
            cheats/health_hook_x86.asm
            )

endif()

set(sources
        ${asm_sources}
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
        cheats/movement.h
        cheats/chat.cpp
        cheats/chat.h cheats/triggerbot.cpp cheats/triggerbot.h ../libgamehackutils/cheatloop.cpp ../libgamehackutils/cheatloop.h)

set_source_files_properties(${asm_sources} PROPERTIES LANGUAGE ASM_NASM)

add_library(achacks SHARED
        ${sources}
        )

target_link_libraries(achacks
        libgamehackutils
        )

target_precompile_headers(achacks PRIVATE pch.h)

enable_language(ASM_NASM)

set(asm_sources
        get_base_address_x86.asm
        cheats/health_hook_x86.asm
        )

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
        cheats/movement.h
        ${asm_sources}
        )

set_source_files_properties(${asm_sources} PROPERTIES LANGUAGE ASM_NASM)

add_library(achacks SHARED
        ${sources}
        )

target_link_libraries(achacks
        libgamehackutils
        )

target_precompile_headers(achacks PRIVATE pch.h)

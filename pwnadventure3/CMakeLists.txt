enable_language(ASM_NASM)

set(asm_sources
        )

set(sources
        ${asm_sources}
        dllmain.cpp
        cheats.cpp
        cheats.h
        pch.h
        framework.h
        offsets.h
        cheats/packet_capture.cpp
        cheats/packet_capture.h
        )

set_source_files_properties(${asm_sources} PROPERTIES LANGUAGE ASM_NASM)

add_library(pwnadventure3 SHARED
        ${sources}
        )

target_link_libraries(pwnadventure3
        libgamehackutils
        )

target_precompile_headers(pwnadventure3 PRIVATE pch.h)

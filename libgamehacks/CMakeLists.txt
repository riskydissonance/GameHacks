enable_language(ASM_NASM)

if (CMAKE_ARCH STREQUAL "x64")

    set(asm_sources
            utils/get_base_address_x64.asm
            )

else ()

    set(asm_sources
            utils/get_base_address_x86.asm
            )

endif ()

set(sources
        ${asm_sources}
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
        state/statemachine.cpp
        state/statemachine.h
        state/state.h
        maths/vector.h
        maths/geometry.h
        cheat/cheat.h
        cheat/cheatlist.cpp
        cheat/cheatlist.h
        utils/utils.h
        3d/opengl/opengl.h
        3d/opengl/opengl.cpp)

set_source_files_properties(${asm_sources} PROPERTIES LANGUAGE ASM_NASM)

add_library(libgamehackutils STATIC
        ${sources}
        )

target_include_directories(libgamehackutils PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )

target_precompile_headers(libgamehackutils PRIVATE pch.h)

cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_COMPILER "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/Llvm/x64/bin/clang.exe")
set(CMAKE_C_COMPILER "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/Llvm/x64/bin/clang.exe")
set(CMAKE_RC_COMPILER "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/Llvm/x64/bin/clang.exe")
project(achacks)

set(CMAKE_CXX_STANDARD 20)


#string(REPLACE "/GR" "/GR-" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}) # Remove RTTI to make it harder to RE

add_subdirectory(libgamehacks)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


if (CMAKE_ARCH STREQUAL "x64")

else ()

    add_subdirectory(achacks)

endif ()

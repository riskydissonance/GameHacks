#pragma once

#include "playerent.h"

const typedef void (* _cheatLoopFunc)(const uintptr_t& baseAddress, playerent* pPlayer, const mem::Mem& mem, const logging::Logger& logger);

void __stdcall cheatLoop(HMODULE const hModule);

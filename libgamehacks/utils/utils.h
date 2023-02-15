#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>


extern "C" uintptr_t __cdecl getBaseAddress();

void hexdump(const int counter, std::basic_ostream<char>& outStream, const BYTE data[], const int length);

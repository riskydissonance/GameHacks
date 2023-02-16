#include <vector>

template<typename T>
T mem::Mem::readMem(uintptr_t targetAddress) const {
    T value;
    memcpy(&value, targetAddress, sizeof(T));
    return value;
}

template<typename T>
T mem::Mem::writeMem(uintptr_t targetAddress, T newValue) const {

    T originalValue = readMem<T>(targetAddress);

    DWORD oldProtect;
    if (!nativeFunctions.VirtualProtect((LPVOID) targetAddress, sizeof(T), PAGE_EXECUTE_READWRITE, &oldProtect)) {
        return false;
    }

    memcpy(targetAddress, &newValue, sizeof(T));

    nativeFunctions.VirtualProtect((LPVOID) targetAddress, sizeof(T), oldProtect, nullptr);
}

bool mem::Mem::readMem(const uintptr_t targetAddress, const size_t length, BYTE* readBytes) const {
    memcpy(readBytes, (void*) targetAddress, length);;
    return true;
}

bool mem::Mem::writeMem(const uintptr_t targetAddress, const BYTE* bytes, const size_t length, BYTE* originalBytes) const {
    DWORD oldProtect;

    if (!nativeFunctions.VirtualProtect((LPVOID) targetAddress, length, PAGE_EXECUTE_READWRITE, &oldProtect)) {
        return false;
    }

    if (originalBytes) {
        readMem(targetAddress, length, originalBytes);
    }

    memcpy((BYTE*) targetAddress, bytes, length);

    nativeFunctions.VirtualProtect((LPVOID) targetAddress, length, oldProtect, nullptr);
    return true;
}

bool mem::Mem::nop(const uintptr_t targetAddress, const size_t length, BYTE* originalBytes) const {
    DWORD oldProtect;

    if (!nativeFunctions.VirtualProtect((LPVOID) targetAddress, length, PAGE_EXECUTE_READWRITE, &oldProtect)) {
        return false;
    }

    if (originalBytes) {
        readMem(targetAddress, length, originalBytes);
    }

    memset((void*) targetAddress, 0x90, length);

    nativeFunctions.VirtualProtect((LPVOID) targetAddress, length, oldProtect, nullptr);
    return true;
}

bool mem::Mem::hookFunc(const uintptr_t hookAddress, const uintptr_t funcAddress, BYTE* originalBytes, const size_t overwriteLength, const bool jmpNotCall) const {

    if(overwriteLength < NEAR_JMP_INSTRUCTION_LENGTH){
        logger.debug_log("[-] Unable to hook function as hook length is less than jmp length (%d): %d", NEAR_JMP_INSTRUCTION_LENGTH, overwriteLength);
        return false;
    }

    auto relativeOffset = (uintptr_t) funcAddress - (hookAddress + NEAR_JMP_INSTRUCTION_LENGTH);
    // Create space for address with null bytes
    std::vector<BYTE> hookBytes = { 0xe8, 0x00, 0x00, 0x00, 0x00 };

    if (jmpNotCall){
        hookBytes = { 0xe9, 0x00, 0x00, 0x00, 0x00 };
    }

    for(int i = NEAR_JMP_INSTRUCTION_LENGTH; i < overwriteLength; i++){
        hookBytes.push_back(0x90);
    }

    // Patch the null bytes with the relative offset from the hook point to the original function
    if (!this->writeMem(((uintptr_t) &hookBytes[0]) + 1, (BYTE*) &relativeOffset, NEAR_JUMP_OPERAND_LENGTH, originalBytes)) {
        return false;
    }

    // Write the patched hook to the hook address
    return this->writeMem(hookAddress, &hookBytes[0], overwriteLength, originalBytes);
}

bool mem::Mem::patchHookFunc(const uintptr_t hookAddress, const uintptr_t funcAddress, const BYTE* originalBytes, const size_t overwriteLength, const bool jmpNotCall, const int hookLength) const {

    if((overwriteLength + NEAR_JMP_INSTRUCTION_LENGTH)  > HOOK_NOP_PLACEHOLDER_LENGTH){
        return false;
    }
    BYTE originalHookBytes[15]{};
    std::vector<BYTE> hookBytes = { 0xe8, 0x00, 0x00, 0x00, 0x00 };

    if (jmpNotCall){
        hookBytes = { 0xe9, 0x00, 0x00, 0x00, 0x00 };
    }

    // Patch the null bytes with the relative offset from the hook point to the original function
    auto relativeOffset = (uintptr_t) hookAddress - (funcAddress + NEAR_JMP_INSTRUCTION_LENGTH + overwriteLength + hookLength);
    if (!this->writeMem(((uintptr_t) &hookBytes[0]) + 1, (const BYTE*) &relativeOffset, NEAR_JUMP_OPERAND_LENGTH, originalHookBytes)) {
        return false;
    }

    // Patch the hook with the original bytes before returning
    if(!this->writeMem((uintptr_t)funcAddress + NEAR_JMP_INSTRUCTION_LENGTH + hookLength, (BYTE*)originalBytes, overwriteLength, originalHookBytes)){
        return false;
    }

    // Patch the hook with the jmp back
    if(!this->writeMem((uintptr_t)funcAddress + NEAR_JMP_INSTRUCTION_LENGTH + hookLength + overwriteLength,(BYTE*)&hookBytes[0], NEAR_JMP_INSTRUCTION_LENGTH, originalHookBytes)){
        return false;
    }

    return true;

}

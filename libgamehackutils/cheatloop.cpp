#include "cheatloop.h"

void cheatloop::CheatLoop::registerLoopFunc(_cheatLoopFunc cheatLoopFunc) {
    cheatLoopFuncs.push_back(cheatLoopFunc);
}

void cheatloop::CheatLoop::unregisterLoopFunc(const _cheatLoopFunc cheatLoopFunc) {
    cheatLoopFuncs.remove(cheatLoopFunc);
}

void cheatloop::CheatLoop::executeLoopFuncs() {
    for (auto cheatLoopFunc : cheatLoopFuncs) {
        if (cheatLoopFunc) {
            cheatLoopFunc(baseAddress, pPlayer, mem, logger);
        }
    }
}

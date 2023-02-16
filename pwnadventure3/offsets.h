#pragma once

static const uintptr_t SOCKET_SEND_HOOK_OFFSET = 0x60a30;
static const uintptr_t SOCKET_RECV_HOOK_OFFSET = 0x6098e;
static const uintptr_t SOCKET_SEND_HOOK_LENGTH = 6;
static const uintptr_t SOCKET_RECV_HOOK_LENGTH = 5;
static const static size_t SOCKET_SEND_HOOK_FUNC_LENGTH = 28;
static const static size_t SOCKET_RECV_HOOK_FUNC_LENGTH = 22;

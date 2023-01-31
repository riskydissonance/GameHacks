section text

global getBaseAddress

getBaseAddress:
    mov eax, dword [fs:0x30]
    mov eax, dword [ds:rax+0x8]
    ret

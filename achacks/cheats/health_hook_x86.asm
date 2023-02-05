section text

global ?infiniteHealthHook@@YAXXZ

?infiniteHealthHook@@YAXXZ:
    cmp dword [ebx+4-0xec+0x1d8], 0
    jne end
    sub dword [ebx+0x4], esi
    mov eax, esi
end:
    ret

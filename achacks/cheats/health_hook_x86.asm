section text

global ?infiniteHealthHook@@YAXXZ

?infiniteHealthHook@@YAXXZ:
    cmp dword [ebx+0xac], 0
    jne end
    mov dword [ebx+0x4], 0
end:
    ret

section text

global ?getBaseAddress@@YAIXZ

?getBaseAddress@@YAIXZ:
    mov eax, dword [fs:0x30]
    mov eax, dword [ds:eax+0x8]
    ret

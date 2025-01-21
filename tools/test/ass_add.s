[bits 32]
section .text
global ass_add
ass_add:
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8]
    mov edx, [ebp + 0xc]
    add eax, edx
    pop ebp
    ret
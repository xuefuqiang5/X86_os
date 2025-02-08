section .text
global save_context
  save_context:
    add esp, 4
    mov eax, [esp]
    push ds 
    push es 
    push fs 
    push gs 
    pushad
    jmp $
    push eax
    ret  
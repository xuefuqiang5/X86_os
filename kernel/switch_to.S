section .text 
global switch_to
switch_to:
    push esi
    push edi
    push edx 
    push ebp 
    mov eax, [esp + 20]
    mov [eax], esp 

    mov eax, [esp + 24]
    mov esp, [eax]
    pop ebp 
    pop edx
    pop edi 
    pop esi
    ret
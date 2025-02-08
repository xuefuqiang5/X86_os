global switch_context
switch_context:
    ;get cur ptr
    mov eax, [esp + 4]
    mov ecx, ebx
    ;get next ptr
    mov edx, [esp + 8]
    ;save cur_stack_ptr
    mov ebx, [eax] 
    sub ebx, 19 * 4
    sub ebx, 8 * 4
    mov [ebx], ebp
    mov [ebx + 4], ecx
    mov [ebx + 8], edi
    mov [ebx + 12], esi
    mov [ebx + 16], eip

    ;load next_stack_ptr

    ret
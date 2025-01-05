%include "boot.inc"
section load vstart=0x900
jmp detected_memory
db 0x00
GDT_ADDR:
    GDT_BASE:
        dd 0x00000000
        dd 0x00000000
    CODE_GDT:
        dd 0x0000ffff
        dd 0x00cf9200
    DATA_GDT:
        dd 0x0000ffff
        dd 0x00cf9200
    VIDEO_GDT:
        dd 0x8000ffff
        dd 0x0040920b
    gdt_ptr:
        dw $ - GDT_ADDR - 1
        dd GDT_ADDR
    ards_buf times 254 db 0 
    ards_count dd 0 
detected_memory:
    mov eax, 0
    mov ds, eax
    mov ax, 0x8000
    mov ss, ax
    xor ebx, ebx 
    xor eax, eax
    mov es, ax 
    mov edi, ards_buf
    mov ecx, 20
    mov edx, 0x534d4150 
    .probe_loop:
        mov eax, 0xe820
        int 0x15
        jc .probe_end
        cmp ebx, 0
        je .probe_end
        add di, cx
        inc dword [es:ards_count]
        loop .probe_loop
    .probe_end
    .culculate_memory:
        mov word cx, [es:ards_count]
        mov edi, ards_buf
        xor eax, eax
        push eax
        .cmp_loop: 
            mov eax, [es:edi]
            mov edx, [es:edi + 8]
            add eax, edx
            pop edx
            push edx
            cmp eax, edx
            jg .push_eax
            jle .next
            .push_eax: 
		        pop edx
                push eax
            .next:
                add edi, 20 
                loop .cmp_loop
    pop eax 
setup_page_table:
    .clear_memory:
        mov ecx, 4096
        mov edi, PAGE_DIR_TABLE_POS
        .clear_loop:
            mov byte [edi], 0x00
            inc edi
            loop .clear_loop
    set_dir_table:
        mov ebx, PAGE_DIR_TABLE_POS
        mov eax, PAGE_DIR_TABLE_POS + 0x1000
        mov edi, 0
        mov ecx, 1024
        .set_dir_loop:
            mov [ebx + edi], eax
            add edi, 4
            mov eax, eax + 0x1000
            loop .set_dir_loop

loader_start:
    in al, 0x92
    or al, 2
    out 0x92, al

    lgdt [cs:gdt_ptr]

    mov eax, cr0
    or eax, 1
    mov cr0, eax

    jmp $



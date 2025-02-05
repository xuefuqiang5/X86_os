%include "boot.inc"

section load vstart=0x900
jmp loader_start
db 0x00
GDT_ADDR:
    GDT_BASE:
        dd 0x00000000
        dd 0x00000000
    CODE_GDT:
        dd 0x0000ffff
        dd 0x00cf9800
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
                pop ebx
                push eax
            .next:
                add edi, 20 
                loop .cmp_loop
            pop eax 
            ret 
    
loader_start:
    call detected_memory
    mov [es:total_mem_addr], eax
    mov eax, 0x00
    mov ds, eax
    in al, 0x92
    or al, 2
    out 0x92, al
    lgdt [gdt_ptr]
    mov eax, cr0 
    or eax, 0x00000001 
    mov cr0, eax 
    jmp dword CODE_SELECTOR:p_mode_start    

[bits 32]
p_mode_start:
    mov ax, DATA_SELECTOR 
    mov ds, ax 
    mov es, ax 
    mov ss, ax 
    mov esp, 0x7c00
    mov ebp, esp
    mov ax, VIDEO_SELECTOR 
    mov gs, ax 
    mov esi, msg
    call print_string 

    mov eax, KERNEL_START_SECTOR
    mov ebx, KERNEL_START_ADDR
    mov ecx, 200
    call read_disk_m_32
    call setup_page_table
    sgdt [gdt_ptr]
    mov ebx, [gdt_ptr + 2]
    or dword [ebx + 0x18 + 4], 0xc0000000
    add esp, 0xc0000000
    mov eax, PAGE_DIR_TABLE_POS
    mov cr3, eax
    mov eax, cr0
    or eax, 0x80000000
    mov cr0, eax
    lgdt [gdt_ptr]
    jmp CODE_SELECTOR:enter_kernel
enter_kernel:
    call kernel_init
    mov eax, VIDEO_SELECTOR
    mov gs, eax
    mov esi, msg1
    call print_string
    mov esp, 0xc009f000
    jmp [vstart]

setup_page_table:
    mov eax, DATA_SELECTOR
    mov ds, eax
    mov ecx, 4096
    mov edi, PAGE_DIR_TABLE_POS
    .clear_page_dir:
        mov byte [edi], 0
        inc edi
        loop .clear_page_dir 
    .setup_page_dir:
        mov eax, PAGE_DIR_TABLE_POS
        add eax, 0x1000
        mov ebx, eax
        or eax, PG_US_U | PG_RW_W | PG_P
        mov [PAGE_DIR_TABLE_POS + 0x0], eax
        mov [PAGE_DIR_TABLE_POS + 0xc00], eax
        sub eax, 0x1000
        mov [PAGE_DIR_TABLE_POS + 4092], eax        ;最后一个页目录表项指向自身
    .setup_page_table:
        mov ecx, 256
        mov esi, 0
        mov edx, PG_US_U | PG_RW_W | PG_P
        .create_pte:
            mov [ebx + esi * 4], edx
            add edx, 4096
            inc esi
            loop .create_pte
        .setup_kernel_pde:
            mov eax, PAGE_DIR_TABLE_POS
            add eax, 0x2000
            or eax, PG_US_U | PG_RW_W | PG_P
            mov ebx, PAGE_DIR_TABLE_POS
            mov ecx, 254
            mov esi, 769
            .create_kernel_pde:
                mov [ebx + esi * 4], eax
                inc esi
                add eax, 0x1000
                loop .create_kernel_pde
            ret
read_disk_m_32:
    mov esi, eax
    mov al, cl
    mov dx, 0x1f2
    out dx, al 
    mov eax, esi 
    mov dx, 0x1f3
    out dx, al 
    shr eax, 8
    mov dx, 0x1f4
    out dx, al 
    mov dx, 0x1f5
    shr eax, 8
    out dx, al
    mov dx, 0x1f6
    shr eax, 8
    and al, 0x0f
    or al, 0xe0
    out dx, al
.read_data:
    mov dx, 0x1f7
    mov al, 0x20
    out dx, al 
.not_ready:
    nop 
    in al, dx
    and al, 0x88
    cmp al, 0x08
    jne .not_ready 
.read_init: 
    mov eax, ecx 
    mov edx, 256
    mul edx
    mov ecx, eax
    mov dx, 0x1f0
.go_on:
    in ax, dx 
    mov [ebx], ax 
    add ebx, 2
    loop .go_on
    ret

print_string:
    push eax
    push edi
    mov edi, 160
    .print_loop:
        ds lodsb
        cmp al, 0
        je print_end
        mov byte [gs:di], al
        inc di
        mov byte [gs:di], 0xa4
        inc di 
    jmp .print_loop
    print_end
    pop eax
    pop edi
    ret
   
kernel_init:
    xor eax, eax
    xor ebx, ebx
    xor ecx, ecx
    xor edx, edx
    xor esi, esi
    xor edi, edi
    mov ebx, KERNEL_START_ADDR
    mov edx, KERNEL_START_ADDR
    mov cx, [ebx + E_PHNUM]
    mov eax, [ebx + E_PHOFF]
    add ebx, eax
    mov esi, 0
    .load_segment:
        mov eax, [ebx + esi + P_TYPE]
        cmp eax, PT_LOAD
        jne .next
        push ecx 
        mov ecx, [ebx + esi + P_FILESZ]
        mov eax, [ebx + esi + P_OFFSET]
        add eax, edx
        mov edi, [ebx + esi + P_VADDR]
        call memcpy
        pop ecx
        .next:
            add esi, 32
            loop .load_segment
        mov eax, [edx + E_ENTRY]
        mov [vstart], eax
        ret
memcpy:
    push esi
    push edi
    mov esi, eax
    rep movsb
    pop edi
    pop esi
    ret



msg db "protect mode", 0
msg1 db "kernel has been loaded!", 0
vstart db 0x00000000

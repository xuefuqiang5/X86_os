%include "boot.inc"
section mbr vstart = 0x7c00 
jmp code_start   
code_start:
    mov ax, 0x600
    mov bx, 0x700
    mov cx, 0
    mov dx, 0x184f
    
    int 0x10
 print_char:
    mov ax, 0xb800
    mov ds, ax 
    mov si, message
    mov di, 0 
    mov ax, 0x07c0 
    mov es, ax
  print_loop:
    es lodsb
    cmp al, 0
    je print_end
    mov byte [di], al
    inc di
    mov byte [di], 0xa4
    inc di 
    jmp print_loop
 print_end

read_sector_to_memory:
 init_data:
    xor eax, eax 
    mov eax, LOADER_START_SECTION
    mov cx, 1
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
 read_data:
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
    mov ax, 0x00
    mov es, ax 
    mov ax, cx 
    mov dx, 256
    mul dx
    mov cx, ax
    mov dx, 0x1f0
    mov bx, LOADER_START_ADDR 
 .go_on:
    in ax, dx 
    mov [es:bx], ax 
    add bx, 2
    loop .go_on
 print_char2:
    mov ax, 0xb800
    mov ds, ax 
    mov si, msg2
    mov di, 0 
    mov ax, 0x07c0 
    mov es, ax
  print_loop2:
    es lodsb
    cmp al, 0
    je print_end2
    mov byte [di], al
    inc di
    mov byte [di], 0xa4
    inc di 
    jmp print_loop2
 print_end2


jmp $
message db "Wecome to my OS!" , 0
msg2 db "the sector has been readed!" , 0

times 510-($-$$) db 0
db 0x55, 0xaa
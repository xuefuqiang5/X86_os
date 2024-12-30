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
    mov byte [0], 'W'
    mov byte [1], 0x04
    mov byte [2], 'e'
    mov byte [3], 0x04
    mov byte [4], 'c'
    mov byte [5], 0x04
    mov byte [6], 'o'
    mov byte [7], 0x04
    mov byte [8], 'm'
    mov byte [9], 0x04
    mov byte [10], 'e'
    mov byte [11], 0x04
    mov byte [12], '!'
    mov byte [13], 0x04
read_sector_to_memory: 
    
jmp $
message db "Wecome to my OS"
times 510-($-$$) db 0
db 0x55, 0xaa
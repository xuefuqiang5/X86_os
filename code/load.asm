%include "boot.inc"
section load vstart = 0x900
jmp loader_start 
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
loader_start:
    in al, 0x92
    or al, 2
    out 0x92, al

    lgdt [cs:gdt_ptr]

    mov eax, cr0
    or eax, 1
    mov cr0, eax

    jmp $



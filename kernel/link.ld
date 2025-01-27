ENTRY(main)

SECTIONS
{
    . = 0xc0001500;

    .text : {
        *(.text)
    }

    .rodata : {
        *(.rodata)
    }

    .data : {
        *(.data)
    }

    .bss : {
        *(.bss)
        PROVIDE(_BSS_END = .);  
    }
}


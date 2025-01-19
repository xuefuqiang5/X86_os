/* link.ld - 链接脚本 */
ENTRY(_start)

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
    }
}
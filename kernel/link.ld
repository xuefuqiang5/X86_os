/* link.ld - 链接脚本 */
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
    } 
}


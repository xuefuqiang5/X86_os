#include "klib.h"
void _assert(char *expression, char *_file, int _line){
    put_str("assert fail \0");
    put_str(expression);
    put_char(' ');
    put_str(_file);
    put_char(' ');
    put_int_dec(_line);
    put_char('\n');
    intr_disable();
}



typedef struct {
    uint32_t flags;
} Flags;


bool is_enable_interrupts(void) {
    Flags flags;
   
    asm volatile (
        "pushf\n\t"  
        "pop %0\n\t" 
        : "=r" (flags.flags)
    );
    return (flags.flags & (1 << 9)) != 0;
}
void set_intr_status(uint32_t status){
    assert(status == 0x200 || status == 0x00); 
    if(status == 0x200) intr_enable();
    else intr_disable();
}
#include "idt.h"
#include "isr.h"
#include "pic.h"
extern char _BSS_END;
int main(){
    clear();
    //idt_init();
    //void (*base)(void) = general_program;
    //for (int i = 0; i < 30; i++){
        //idt_register(i, 0x06, base);
    //}
    uint32_t heapAddr = &_BSS_END;
    put_str("heap start addr is :  \0");
    put_char('\n');
    assert(10 > 20);
    assert(10 < 20);
    assert(10 == 20);
    uint32_t a = intr_disable();
    
    while(1);
}
#include "idt.h"
#include "isr.h"
#include "pic.h"
#include "memory.h"
extern char _BSS_END;
int main(){
    clear();
    idt_init();
    void (*base)(void) = general_program;
    for (int i = 0; i < 30; i++){
        idt_register(i, 0x06, base);
    }
    
    uint32_t a = intr_disable();
    mem_init();
    while(1);
}
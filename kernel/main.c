#include "idt.h"
#include "isr.h"
#include "pic.h"
int main(){
    clear();
    idt_init();
    void (*base)(void) = general_program;
    for (int i = 0; i < 30; i++){
        idt_register(i, 0x06, base);
    }
    pic_init();
    pic_clearmask(0);
    asm volatile("sti");
    while(1);
    
}
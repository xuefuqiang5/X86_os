#include "idt.h"
#include "isr.h"
#include "pic.h"
int main(){
    clear();
    idt_init();
    void (*base)(void) = general_program;
    for (int i = 0; i < 20; i++){
        idt_register(i, 0x06, base);
    }
    int a = 10 / 0 ;
}
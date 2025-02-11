#include "idt.h"
#include "isr.h"
#include "pic.h"
#include "memory.h"
#include "timer.h"
#include "thread.h"
extern char _BSS_END;
extern void *intr_entry_table[33];
extern void *idt_table[33];
void pfunc(void *arg);
int main(){
    clear();
    idt_init();
    pic_init();
    timer_init();
    //idt_register(20, 0x06, intr_entry_table[20]);
    //for(int i = 0; i < 33; i++) {put_int_hex(intr_entry_table[i]); put_char('\n');}
    for(int i = 0; i < 33; i++) {idt_register(i, 0x06, intr_entry_table[i]);}
    init_idt_table();
    
    
    //pic_clearmask(0); 
    intr_enable();
    pic_clearmask(0);
    uint32_t a = 10000;
    while(a--);
    intr_disable();
    pic_setmask(0);
    put_char('a');
    while(1);
}
void pfunc(void *arg){
    char *para = arg;
        put_str(para);
}

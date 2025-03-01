#include "init.h"
void init_all(){
    clear();
    idt_init();
    pic_init();
    timer_init();
    mem_init();
    for(int i = 0; i < IDT_DESC_CNT; i++) {idt_register(i, 0x06, intr_entry_table[i]);}
    init_idt_table();
    register_intr_handler(0x20, clock_interrupt); 
    init_list();
    init_main_thread();
    console_init();  
    init_keyboard();
}
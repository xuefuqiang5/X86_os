
#include "isr.h"
void *idt_table[33];
void general_program(uint32_t vecnum){
    if(vecnum == 0x20 ) return;
    put_str("the thread name is  ");
    struct task_struct* cur_thread = running_thread();
    put_str(cur_thread->name);
    put_char('\n');
    put_str("the vecnum  = ");
    put_int_hex(vecnum);
    put_char('\n');
    
}
void init_idt_table(){
    for(int i = 0; i < 33; i++) idt_table[i] = general_program;
}
void register_intr_handler(uint32_t vecnum, isr_func func){
    idt_table[vecnum] = func;
}
void clock_interrupt(){
    struct task_struct* cur_thread = running_thread();
    //put_int_hex((uint32_t) cur_thread);
    //put_char('\n');
    assert(cur_thread->stack_magic == MAGIC_NUM);//0x19940625
    cur_thread->elapsed_ticks++;
    cur_thread->ticks--;
    if(cur_thread->ticks == 0){
        schedule();
    }else{
        cur_thread->ticks--;
    }
}

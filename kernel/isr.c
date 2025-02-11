
#include "isr.h"
void *idt_table[33];
void general_program(uint32_t vecnum){
    put_str("the vecnum  = ");
    put_int_hex(vecnum);
    put_char('\n');
}
void init_idt_table(){
    for(int i = 0; i < 33; i++) idt_table[i] = general_program;
}
void clock_interrupt(){
    struct task_struct* cur_thread = running_thread();
    assert(cur_thread->stack_magic == 0x19940625);
    cur_thread->elapsed_ticks++;
    cur_thread->ticks--;
    if(cur_thread->ticks == 0){
        schedule();
    }else{
        cur_thread->ticks--;
    }
}
void isr_register(uint8_t vec_no, isr_func function){
    change_func_addr(vec_no, function);
}
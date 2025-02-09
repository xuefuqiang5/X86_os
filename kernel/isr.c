
#include "isr.h"
void *isr_entry_table[33];
void init_isr_table(){
    for(int i =  0; i < 33; i++) isr_entry_table[0] = 0;
    ISR_FUNC(0, 0);
    ISR_FUNC(1, 0);
    ISR_FUNC(2, 0);
    ISR_FUNC(3, 0);
    ISR_FUNC(4, 0);
    ISR_FUNC(5, 0);
    ISR_FUNC(6, 0);
    ISR_FUNC(7, 0);
    ISR_FUNC(8, 0);
    ISR_FUNC(9, 0);
    ISR_FUNC(10, 0);
    ISR_FUNC(11, 0);
    ISR_FUNC(12, 0);
    ISR_FUNC(13, 0);
    ISR_FUNC(14, 0);
    ISR_FUNC(15, 0);
    ISR_FUNC(16, 0);
    ISR_FUNC(17, 0);
    ISR_FUNC(18, 0);
    ISR_FUNC(19, 0);
    ISR_FUNC(20, 0);
    ISR_FUNC(21, 0);
    ISR_FUNC(22, 0);
    ISR_FUNC(23, 0);
    ISR_FUNC(24, 0);
    ISR_FUNC(25, 0);
    ISR_FUNC(26, 0);
    ISR_FUNC(27, 0);
    ISR_FUNC(28, 0);
    ISR_FUNC(29, 0);
    ISR_FUNC(30, 0);
    ISR_FUNC(31, 0);
    ISR_FUNC(32, 0);
    flag = 1;
}
void general_program(){
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
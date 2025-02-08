#include "thread.h"
#include "isr.h"
#include "pic.h"
#include "idt.h"
void *isr_entry_table[33];
#define ZERO_ACTION do { asm volatile("pushl $0"); } while (0)
#define ERROR_ACTION do { asm volatile("nop"); } while (0)
#define INIT_ISR(vecnum, error_code) \
    do { \
        if ((error_code) == 0) { \
            ZERO_ACTION; \
        } else { \
            ERROR_ACTION; \
        } \
        asm volatile("push %ds"); \
        asm volatile("push %es"); \
        asm volatile("push %fs"); \
        asm volatile("push %gs"); \
        asm volatile ("pusha\n\t" ::: "memory");   \
        out8(0xa0, 0x20); \
        out8(0x20, 0x20); \
        asm volatile("push %0" : : "r" (vecnum) : "memory"); \
    } while (0)

#define EXIT_ISR()               \
    do{                          \
        asm volatile ("add $4, %esp");      \
        asm volatile("popa");    \
        asm volatile("pop %gs");  \
        asm volatile("pop %fs");  \
        asm volatile("pop %es");  \
        asm volatile("pop %ds");  \
        asm volatile("add $4, %esp");\
        while(1);\
        asm volatile("iret"); \
    }while(0)
void general_program(){
    //INIT_ISR(0, 0);
    set_cursor_pos(80 * 3);
    put_str("General Protection Fault");
    intr_disable();
    //EXIT_ISR();
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
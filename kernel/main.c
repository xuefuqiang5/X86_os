#include "idt.h"
#include "isr.h"
#include "pic.h"
#include "memory.h"
#include "timer.h"
#include "thread.h"
#include "semaphore.h"
#include "console.h"
extern char _BSS_END;
extern void *intr_entry_table[33];
extern void *idt_table[33];
void k_thread_a(void *arg);
void k_thread_b(void *arg);
struct lock mutex;
int main(){
    clear();
    idt_init();
    pic_init();
    timer_init();
    mem_init();



    //idt_register(20, 0x06, intr_entry_table[20]);
    //for(int i = 0; i < 33; i++) {put_int_hex(intr_entry_table[i]); put_char('\n');}
    for(int i = 0; i < 33; i++) {idt_register(i, 0x06, intr_entry_table[i]);}
    init_idt_table();
    register_intr_handler(0x20, clock_interrupt); 
    //pic_clearmask(0); 
    init_list();
    init_main_thread();
    console_init();  
    thread_start("thread_a", 15, k_thread_a, "arg_a\n");
    thread_start("thread_b", 31, k_thread_b, "arg_b");
    intr_enable();
    pic_clearmask(0);
    //thread_start("hello1", 15, pfunc2, "arg2 ");
    while(1){
        console_put_str(" Main");
    }
    return 0; 
}

void k_thread_a(void* arg) {
    char* para = arg;
    while(1) {
        console_put_str(para);
    }
}

void k_thread_b(void* arg) {
    char* para = arg;
    while(1) {
        console_put_str(para);
    }
}
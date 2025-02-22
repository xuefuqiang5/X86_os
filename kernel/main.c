#include "idt.h"
#include "isr.h"
#include "pic.h"
#include "memory.h"
#include "timer.h"
#include "thread.h"
#include "semaphore.h"
extern char _BSS_END;
extern void *intr_entry_table[33];
extern void *idt_table[33];
struct semaphore mutex;
void pfunc(void *arg);
void pfunc2(void *arg);
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
    
    
    intr_enable();
    pic_clearmask(0);
    
    thread_start("hello", 31, pfunc, "arg ");
    //thread_start("hello1", 15, pfunc2, "arg2 ");
    sema_init(&mutex, 1);
    while(1){  
    sema_wait(&mutex);
    put_str("Main ");
    sema_post(&mutex);
    }
    
}
void pfunc(void *arg){
    char *para = arg;
        while (1) {
            sema_wait(&mutex);
            put_str(para);
            sema_post(&mutex);
        }
}
void pfunc2(void *arg){
    char *para = arg; 
    while(1) {intr_disable(); put_str(para);intr_enable(); }
}
#include "idt.h"
#include "isr.h"
#include "pic.h"
#include "memory.h"
#include "timer.h"
#include "thread.h"
extern char _BSS_END;
void pfunc(void *arg);
int main(){
    clear();
    idt_init();
    //timer_init();
    void (*base)(void) = general_program;
    for (int i = 0; i < 30; i++){
        idt_register(i, 0x06, base);
    } 
    pic_init();
    timer_init();
    pic_clearmask(0);
    
    intr_enable();
    //uint32_t a = intr_disable();
    //mem_init();
    //thread_start("pfunc", 31, pfunc, "hello ");
    //put_char('a');
    while(1);
}
void pfunc(void *arg){
    char *para = arg;
        put_str(para);
}
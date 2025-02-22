#include "init.h"
void k_thread_a(void *arg);
void k_thread_b(void *arg);
int main(){
    init_all();
    register_intr_handler(0x20, clock_interrupt);
    register_intr_handler(0x21, keyboard_intr_handler);
    //thread_start("thread_a", 15, k_thread_a, "arg_a\n");
    //thread_start("thread_b", 31, k_thread_b, "arg_b");
    intr_enable();
    pic_clearmask(0); // open clock intr
    pic_clearmask(1);// open keybroad intr 
    //thread_start("hello1", 15, pfunc2, "arg2 ");
    while(1){
        //console_put_str(" Main");
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
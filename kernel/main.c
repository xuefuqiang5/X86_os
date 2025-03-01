#include "init.h"
void k_thread_a();
void k_thread_b(void *arg);
void print_keybuf();
struct lock mutex;
int main(){
    init_all();
    intr_enable();
    pic_clearmask(0); // open clock intr
    thread_start("print_keybuf", 7, k_thread_a, "print_keybuf");
    pic_clearmask(1);// open keybroad intr 
    while(1){
    }
    return 0; 
}
void k_thread_a(void *arg) {

    while(1) {
        uint32_t old_status = intr_disable();
        
        if(!ioq_is_empty(&keyboard_buf)){
            char c = ioq_getchar(&keyboard_buf);
            console_put_char(c);
            //console_put_str("\n  "); 
            //console_put_str(arg);
        } 
        set_intr_status(old_status);
    }
}

void k_thread_b(void* arg) {
    char* para = arg;
    while(1) {
        console_put_str(para);
    }
}

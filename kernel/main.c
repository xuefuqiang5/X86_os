#include "init.h"
void k_thread_a(void *arg);
void k_thread_b(void *arg);
void print_keybuf();
struct lock mutex;
int main(){
    init_all();
    intr_enable();
    pic_clearmask(0); // open clock intr
    pic_clearmask(1);// open keybroad intr 
    while(1){
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

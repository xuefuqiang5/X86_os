#include "idt.h"
#include "isr.h"
#include "pic.h"
#include "memory.h"
extern char _BSS_END;
int main(){
    clear();
    idt_init();
    void (*base)(void) = general_program;
    for (int i = 0; i < 30; i++){
        idt_register(i, 0x06, base);
    } 
    uint32_t a = intr_disable();
    mem_init();
    uint32_t *heap_data = (uint32_t *)page_allocate(500, PF_KERNEL);
    put_int_hex(heap_data);
    put_char('\n');
    put_int_hex((uint32_t)heap_data + 500 * PAGE_SIZE);
    put_char('\n');
    heap_data[500 * 1024 - 1] = 0x12345678;
    put_int_hex(heap_data[500 * 1024 - 1]);
    put_char('\n');
    put_char('a');
    while(1);
}
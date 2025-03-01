#include "isr.h"
void *idt_table[IDT_DESC_CNT];
void general_program(uint32_t vecnum){
    if(vecnum == 0x20 ) return;
    clear();
    //intr_disable();
    set_cursor_pos(80 * 4);
    put_str("the thread name is  ");
    struct task_struct* cur_thread = running_thread();
    put_str(cur_thread->name);
    put_char('\n');
    put_str("the vecnum  = ");
    put_int_hex(vecnum);
    put_char('\n');
    //while(1);
}
void init_idt_table(){
    for(int i = 0; i < IDT_DESC_CNT; i++) idt_table[i] = general_program;
}
void register_intr_handler(uint32_t vecnum, isr_func func){
    idt_table[vecnum] = func;
}
void clock_interrupt(){
    struct task_struct* cur_thread = running_thread();
    //put_int_hex((uint32_t) cur_thread);
    //put_char('\n');
    assert(cur_thread->stack_magic == MAGIC_NUM);//0x19940625
    cur_thread->elapsed_ticks++;
    cur_thread->ticks--;
    if(cur_thread->ticks == 0){
        schedule();
    }else{
        cur_thread->ticks--;
    }
}
void keyboard_intr_handler(){
    uint8_t s = in8(KEY_PORT);
    if(key_mapping_table[s].ascii == 0) goto key_status;
    char c = key_mapping_table[s].ascii; 
    if(c >= 'a' && c <= 'z') {
        if(modify_key_status.left_shift == 1    ||
            modify_key_status.right_shift == 1  ||
            modify_key_status.caps_lock == 1){c = to_upper(c); goto print_char;}
    }
    if(modify_key_status.left_shift == 1 || modify_key_status.right_shift == 1){
        c =  shift_char(c);
    }
    print_char:
        if(!ioq_is_full(&keyboard_buf)){
            ioq_putchar(c, &keyboard_buf); 
            //put_char(c); 
        }
    return;
    key_status:
        change_key_status(s); 


}

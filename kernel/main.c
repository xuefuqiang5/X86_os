#include "../lib/kernel/klib.h"
int main(){
    clear();
    put_char('a');
    put_char('\n');
    put_str("hello, world !\n\0");
    put_int_hex(0xffffffff);
    for(uint16_t i = 0; i < 10;i++) put_char(CHAR_BACKSPACE);
    put_str("delete ten times");
    while(1);
}
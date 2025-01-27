#include "klib.h"
void _assert(char *expression, char *_file, int _line){
    put_str("assert fail \0");
    put_str(expression);
    put_char(' ');
    put_str(_file);
    put_char(' ');
    put_int_dec(_line);
    put_char('\n');
    intr_disable();
}

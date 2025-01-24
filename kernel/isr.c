
#include "isr.h"
#include "pic.h"
void general_program(){
    put_str("this is general !\0");
    pic_sendeoi(0);
}
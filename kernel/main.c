#include "../lib/kernel/klib.h"
extern void put_char(char c);
int main(){
    clear();
    put_char('a');
    while(1);
}
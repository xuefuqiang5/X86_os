#include "../lib/kernel/put_char.h"
extern void put_char(char c);
int main(){
    char c = 'a';
    for(uint16_t i = 0; i < 25; i++){
        for(uint16_t j = 0; j < 80; j++){
            put_char(c);
        }
        c++;
    }
    put_char('x');
    while(1);
}
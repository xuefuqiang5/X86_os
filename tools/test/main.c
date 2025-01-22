#include "test.h"
#include <stdio.h>
#include <stdint.h>
void put_int_hex(uint32_t num);
int main(){
    put_int_hex(0xffffffff);
    return 0;
}
void put_int_hex(uint32_t num){
    char str[32] = {'0'};
    int16_t i;
    char c = '0';
    for(;; i++){
        if(num == 0) break;
        uint8_t t = num % 16;
        switch (t)
        {
        case 10:str[i] = 'A';
            break;
        case 11:str[i] = 'B';
            break;
        case 12:str[i] = 'C';
            break;
        case 13:str[i] = 'D';
            break;
        case 14:str[i] = 'E';
            break;
        case 15:str[i] = 'F';
            break;
        default:str[i] = c + t;
            break;
        }
        num /= 16;
    }
    i -= 1;
    printf("%d\n", i);
    char a;
    while(i >= 0){
        a = str[i];
        printf("%c", c);
        i--;
    }      
}
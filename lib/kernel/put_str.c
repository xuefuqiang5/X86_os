#include "klib.h"
void put_str(char *str){
    for(uint16_t i = 0;;i++){
        if(str[i] == '\0') return;
        put_char(str[i]);
    }
}
//函数需要修改
void put_int_hex(uint32_t num){
    if(num == 0)  {put_char('0');return;}
    char str[32] = {'0'};
    int16_t i = 0;
    char c = '0';
    for(;; i++){
        if(num == 0)  {break;}
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
    while(i >= 0){
        put_char(str[i]);
        i--;
    }      
}
void put_int_dec(uint32_t num){
    if(num == 0) {put_char('0');return ;}
    char str[32] = {'0'};
    int16_t i = 0;
    char c = '0';
    for(;; i++){
        if(num == 0) {break;}
        uint8_t t = num % 10;
        str[i] = c + t;
        num /= 10;
    }
    i -= 1;
    while(i >= 0){
        put_char(str[i]);
        i--;
    }      
}
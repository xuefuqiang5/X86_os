#include "klib.h"
void strcpy(char *dst, char *src){
    while(*src != '\0'){
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
}
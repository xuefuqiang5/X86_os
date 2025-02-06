#include <stdio.h>

void _strcpy(char *dst, char *src){
    while(*src != '\0'){
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
}
int main(){
    char *src = "hello world";
    char dst[20];
    _strcpy(dst, src);
    printf("%s\n", dst);
    return 0;
}
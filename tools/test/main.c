#include "test.h"
#include <stdio.h>
int main(){
    int a = 0;
    int b = 1; 
    int c = 2;
    asm volatile("add %%ebx, %%eax\r\t"
                 : "=m"(c)
                 : "r"(a), "r"(b)
                 );
    printf("a + b = %d\n", c);
   return 0;
}
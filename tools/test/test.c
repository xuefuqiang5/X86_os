#include <stdio.h>
extern void save_context();
int main(){
    save_context();
    printf("the context has been saved! \n");
    return 0;
}
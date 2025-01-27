#include <stdio.h>
int a(){
    printf("this is function a");
    return 1;
}
int main(){
    printf("the value is %d\n:", 0 || (a(), 0));
}
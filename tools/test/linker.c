#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define offset_of(type, member) \
    (uint32_t)(&((type *)0)->member)
typedef struct Linker{
    struct Linker *next;
    struct Linker *prev;
    void (*add) (void);
}Linker;
struct dataNode{
    int x;
    int y;
};
typedef struct dataAndlink{
    struct Linker linker;
    struct dataNode data;
}dataAndlink;
int main(){
    dataAndlink head;
    head.linker.next = NULL;
    head.linker.prev = NULL;
    for(int i = 0; i < 10; i++){
        dataAndlink *node = (dataAndlink *)malloc(sizeof(dataAndlink));
        node->data.x = i;
        node->data.y = i + 1;
        if(head.linker.next == NULL){
            head.linker.next = (Linker *)node;
            node->linker.prev = (Linker *)&head;
            node->linker.next = NULL;
            continue;
        }
        node->linker.next = head.linker.next;
        head.linker.next->prev = (Linker *)node;
        head.linker.next = (Linker *)node;
        node->linker.prev = (Linker *)&head;
    }
    Linker *node = (Linker *)head.linker.next;
    for(int i = 0; i < 10; i++){
        dataAndlink *n = (dataAndlink *)node;
        printf("x: %d, y: %d\n", n->data.x, n->data.y);
        node = node->next;
        free(n);
    }

}
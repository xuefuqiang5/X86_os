#include "thread.h"
#include "semaphore.h"
#define BUF_SIZE 64
void ioqueue_init();
void is_empty();
void is_full();
char peek(); 
static struct ioqueue{
    struct task_struct *productor;
    struct task_struct *consumer;
    struct lock mutex;
    char buf[BUF_SIZE];
    int32_t head;
    int32_t tail; 
};

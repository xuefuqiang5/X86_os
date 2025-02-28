#include "thread.h"
#include "semaphore.h"
#define BUF_SIZE 64
void ioq_init();
static bool ioq_is_empty(struct ioqueue *i);
static bool ioq_is_full(struct ioqueue *i);
static int32_t next_pos(int32_t pos);
static void ioq_wait(struct task_struct **waiter);
static void ioq_wakeup(struct task_struct ** wairer);
char ioq_getchar(struct ioqueue *i);
void ioq_putchar(char c, struct ioqueue *i);
struct ioqueue{
    struct task_struct *producer;
    struct task_struct *consumer;
    struct lock mutex;
    char buf[BUF_SIZE];
    int32_t head;
    int32_t tail; 
};

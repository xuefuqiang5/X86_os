#include "ioqueue.h"
void ioqueue_init(struct ioqueue *ioqueue){
    memset(ioqueue->buf, 0, BUF_SIZE);
    ioqueue->consumer = NULL;
    ioqueue->producer = NULL;
    lock_init(&ioqueue->mutex);
    ioqueue->head = 0; 
    ioqueue->tail = 0; 
}
int32_t next_pos(int32_t pos){
    return (pos + 1) % BUF_SIZE;
}
static bool ioq_is_empty(struct ioqueue *i){
    assert(!is_enable_interrupts());
    return i->head == i->tail;
}
static bool ioq_is_full(struct ioqueue *i){
    assert(!is_enable_interrupts());
    return next_pos(i->head) == i->tail;
}
static void ioq_wait(struct task_struct **waiter){
    assert(waiter != NULL && *waiter == NULL);
    *waiter = running_thread();
    thread_block(TASK_BLOCKED);
}
static void ioq_wakeup(struct task_struct **waiter){
    assert(waiter != NULL && *waiter != NULL);
    thread_unblock(*waiter);
    *waiter = NULL;
}
void is_empty(struct ioqueue *i){
    lock_acquire(&i->mutex);
    
} 
char ioq_getchar(struct ioqueue *i){
    assert(!is_enable_interrupts());
    while(ioq_is_empty(i)){
        lock_acquire(&i->mutex);
        ioq_wait(&i->consumer);
        lock_release(&i->mutex);
    }
    char c = i->buf[i->tail];
    i->tail = next_pos(i->tail);
    if(i->producer != NULL) ioq_wakeup(&i->producer);
    return c;
}
void ioq_putchar(char c, struct ioqueue *i){
    assert(!is_enable_interrupts());
    while(ioq_is_full(i)){
        lock_acquire(&i->mutex);
        ioq_wait(&i->producer);
        lock_release(&i->mutex);
    }
    i->buf[i->head] = c;
    i->head = next_pos(i->head);
    if(i->consumer != NULL) ioq_wakeup(i->consumer);
}
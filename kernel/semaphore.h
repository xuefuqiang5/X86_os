#pragma once 
#include "../lib/kernel/klib.h"
#include "thread.h"
struct semaphore{
    uint8_t value;
    struct list_head waiter_head;
};
struct lock{
    struct task_struct *holder; 
    struct semaphore semaphore;
    uint32_t lock_rpt_nr;
};
void sema_init(struct semaphore *sema, uint8_t value);
void sema_wait(struct semaphore *sema);
void sema_post(struct semaphore *sema); 
void lock_acquire(struct lock *l);
void lock_release(struct lock *l); 
void lock_init(struct lock *l);
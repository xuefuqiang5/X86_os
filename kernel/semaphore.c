#include "semaphore.h"
void sema_init(struct semaphore *sema, uint8_t value){
    sema->value = value;
    list_init(&sema->waiter_head);
}
void lock_init(struct lock *plock){
    plock->holder = NULL;
    plock->lock_rpt_nr = 0;
    sema_init(&plock->semaphore, 1);
}
void sema_wait(struct semaphore *sema){
    uint32_t old_status = intr_disable();
    if(sema->value > 0){sema->value--; return;}
    struct task_struct *cur = running_thread();
    thread_block(TASK_BLOCKED);
    list_pushback(&cur->general_tag, &sema->waiter_head);
    set_intr_status(old_status);
}
void sema_post(struct semaphore *sema){
    uint32_t old_status = intr_disable(); 
    if(!(list_is_empty(&sema->waiter_head))){
        thread_unblock(list_pop(&sema->waiter_head));
        return;
    }
    sema->value++; 
    set_intr_status(old_status);
}
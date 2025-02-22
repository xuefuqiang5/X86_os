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
    struct task_struct *cur = running_thread();
    while(sema->value == 0) {
        assert(!list_find(&sema->waiter_head, &cur->general_tag));
        if(list_find(&sema->waiter_head, &cur->general_tag)){
            put_str("the thread has been blocked \n");
            while(1);
        }
        list_pushback(&cur->general_tag, &sema->waiter_head);
        thread_block(TASK_BLOCKED);
    }
        sema->value--;
        assert(sema->value == 0);
        set_intr_status(old_status);
}
void sema_post(struct semaphore *sema){
    uint32_t old_status = intr_disable();
    assert(sema->value == 0);
    if(!(list_is_empty(&sema->waiter_head))){
        struct task_struct *thread_blocked = to_entry(list_pop(&sema->waiter_head), struct task_struct, general_tag);
        thread_unblock(thread_blocked);
    }
    sema->value++;
    assert(sema->value == 1);
    set_intr_status(old_status);
}
void lock_acquire(struct lock *l){ 
    if(l->holder != running_thread()){ 
        sema_wait(&l->semaphore);
        l->holder = running_thread();
        assert(l->lock_rpt_nr == 0);
        l->lock_rpt_nr = 1;
    }
    else{l->lock_rpt_nr++;}
}
void lock_release(struct lock *l){
    assert(l->holder == running_thread());
    if(l->lock_rpt_nr > 1) {l->lock_rpt_nr--; return;}
    assert(l->lock_rpt_nr == 1);
    l->holder == NULL; 
    l->lock_rpt_nr = 0;
    sema_post(&l->semaphore);

}
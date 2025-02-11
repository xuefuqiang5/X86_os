#include "thread.h"
#include "memory.h"
struct task_struct *main_thread;
struct task_struct ready_queue_head;
struct task_struct all_queue_head;
static void kernel_thread(thread_func* function, void* func_arg){
    intr_enable();
    function(func_arg);
}
struct task_struct* running_thread(){
    uint32_t esp;
    asm volatile("mov %%esp, %0" : "=g"(esp));
    return (struct task_struct*)PAGE_ALIGN_DOWN(esp);
}
void thread_create(struct task_struct* pthread, thread_func function, void* func_arg){
    pthread->self_kstack -= sizeof(struct intr_stack);
    pthread->self_kstack -= sizeof(struct thread_stack);
    struct thread_stack* kthread_stack = (struct thread_stack*)pthread->self_kstack;
    kthread_stack->eip = kernel_thread;
    kthread_stack->function = function;
    kthread_stack->func_arg = func_arg;
    kthread_stack->ebp = kthread_stack->ebx = kthread_stack->edi = kthread_stack->esi = 0;
}
void init_thread(struct task_struct* pthread, char* name, int prio){
    if(name != "main") memset(pthread, 0, PAGE_SIZE);
    strcpy(pthread->name, name);
    if(pthread == main_thread){
        pthread->status = TASK_RUNNING;
    }else{pthread->status = TASK_READY;}
    pthread->self_kstack = (uint32_t*)((uint32_t)pthread + PAGE_SIZE);
    pthread->elapsed_ticks = 0;
    pthread->priority = prio;
    pthread->ticks = prio;
    pthread->pgdir = NULL;
    pthread->stack_magic = MAGIC_NUM;
}
struct task_struct* thread_start(char* name, int prio, thread_func function, void* func_arg){
    struct task_struct* thread = page_allocate(1, PF_KERNEL);
    init_thread(thread, name, prio);
    thread_create(thread, function, func_arg);
    assert(!list_find(&ready_queue_head.general_tag, &thread->general_tag));
    list_pushback(&ready_queue_head.general_tag, &thread->general_tag);
    assert(!list_find(&all_queue_head.all_list_tag, &thread->all_list_tag));
    list_pushback(&all_queue_head.all_list_tag, &thread->all_list_tag);
    return thread;
}
void init_list(){
    to_link(&ready_queue_head, general_tag)->next = to_link(&ready_queue_head, general_tag);
    to_link(&ready_queue_head, general_tag)->prev = to_link(&ready_queue_head, general_tag);
    to_link(&ready_queue_head, all_list_tag)->next = to_link(&ready_queue_head, all_list_tag);
    to_link(&ready_queue_head, all_list_tag)->prev = to_link(&ready_queue_head, all_list_tag);
}

void init_main_thread(){
    main_thread = running_thread();
    init_thread(main_thread, "main", 31);
    assert(!list_find(&all_queue_head.general_tag, &main_thread->all_list_tag));
    list_pushback(&all_queue_head.all_list_tag, &main_thread->all_list_tag);
}

void schedule(){
    assert(!(is_enable_interrupts()));
    struct task_struct* cur = running_thread();
    if(cur->status == TASK_RUNNING){
        assert(!list_find(&ready_queue_head.general_tag, &cur->general_tag));
        list_pushback(&ready_queue_head.general_tag, &cur->general_tag);
        cur->ticks = cur->priority;
        cur->status = TASK_READY;
    }
    else {}
    
    struct task_struct* next = list_pop(&ready_queue_head.general_tag);
    next->status = TASK_RUNNING;
    switch_to(cur, next);
}


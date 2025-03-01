#pragma once
#include "thread.h"
#include "semaphore.h"
#define BUF_SIZE 64
struct ioqueue{
    struct task_struct *producer;
    struct task_struct *consumer;
    struct lock mutex;
    char buf[BUF_SIZE];
    int32_t head;
    int32_t tail; 
};
void ioq_init(struct ioqueue *i);
char ioq_getchar(struct ioqueue *i);
void ioq_putchar(char c, struct ioqueue *i);
bool ioq_is_empty(struct ioqueue *i);
bool ioq_is_full(struct ioqueue *i);



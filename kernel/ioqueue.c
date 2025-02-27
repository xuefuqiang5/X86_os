#include "ioqueue.h"
void ioqueue_init(struct ioqueue *ioqueue){
    memset(ioqueue->buf, 0, BUF_SIZE);
    ioqueue->consumer = NULL;
    ioqueue->productor = NULL;
    lock_init(&ioqueue->mutex);
    ioqueue->head = 0; 
    ioqueue->tail = 0; 
}
void is_empty(struct ioqueue *i){
    lock_acquire(&i->mutex);
    
} 
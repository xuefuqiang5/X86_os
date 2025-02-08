#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#define offset(type, member) ((size_t)(&((type *)0)->member))
#define to_entry(list_ptr, type, member) \
  ((type *)((char *)(list_ptr) - offset(type, member)))
#define to_link(ptr, member) (&(ptr)->member)
void list_init(struct list_head *hdr) {
  hdr->next = hdr;
  hdr->prev = hdr;
}

int list_is_empty(struct list_head *list) {
  return list->next == list;
}

void list_pushfront(struct list_head *item, struct list_head *list) {
  item->next = list->next;
  item->prev = list;
  list->next->prev = item;
  list->next = item;
}

void list_pushback(struct list_head *item, struct list_head *list) {
  item->next = list;
  item->prev = list->prev;
  list->prev->next = item;
  list->prev = item;
}

void list_append_front(struct list_head *dst, struct list_head *src) {
  if(list_is_empty(src))
    return;
  src->prev->next = dst->next;
  dst->next->prev = src->prev;
  dst->next = src->next;
  src->next->prev = dst;
  list_init(src);
}

void list_append_back(struct list_head *dst, struct list_head *src) {
  if(list_is_empty(src))
    return;
  src->next->prev = dst->prev;
  dst->prev->next = src->next;
  dst->prev = src->prev;
  src->prev->next = dst;
  list_init(src);
}

void list_rotate_forward(struct list_head *list) {
  if(list_is_empty(list))
    return;
  struct list_head *next = list->next;
  list_remove(list);
  list_pushfront(list, next);
}

void list_rotete_backward(struct list_head *list) {
  if(list_is_empty(list))
    return;
  struct list_head *prev = list->prev;
  list_remove(list);
  list_pushback(list, prev);
}

void list_remove(struct list_head *item) {
  item->prev->next = item->next;
  item->next->prev = item->prev;
  list_init(item);
}

struct list_head *list_pop(struct list_head *list) {
  if(list_is_empty(list))
    return NULL;
  struct list_head *first = list->next;
  list_remove(first);
  return first;
}
typedef struct data_t {
  int data;
  struct list_head list;
} data_t;
int main(){
  data_t *data_h = (data_t *)malloc(sizeof(data_t)); 
  list_init(&data_h->list);
  for(int i = 0; i < 10; i++) {
    data_t *data = (data_t *)malloc(sizeof(data_t));
    data->data = i;
    list_pushback(&data->list, &data_h->list);
  }
  printf("the int's size is %ld\n", sizeof(int));
  printf("the data_t size = %ld\n", sizeof(data_t));
  printf("the offset = %ld\n ", offset(data_t, list));
  struct list_head *p = to_link(data_h, list);
  list_foreach(p, &data_h->list) {
    data_t *data = to_entry(p, data_t, list);
    printf("data = %d\n", data->data);
  }
  return 0;
}
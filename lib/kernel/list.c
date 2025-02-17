#include "list.h"
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
bool list_find(struct list_head *list, struct list_head *item) {
  struct list_head *p;
  list_foreach(p, list) {
    if(p == item)
      return true;
  }
  return false;
}

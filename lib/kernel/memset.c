#include "klib.h"
void *memset(void *buffer, uint32_t val, uint32_t size){
    uint32_t *int_ptr = (uint32_t *)buffer;
    while(size--){
        *int_ptr = val;
        int_ptr++;
    }
    return buffer;
}
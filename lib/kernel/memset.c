#include "klib.h"
void *memset(void *buffer, int val, uint32_t byte_size) {
    unsigned char *p = buffer;
    for (uint32_t i = 0; i < byte_size; i++) {
        p[i] = (unsigned char)val;
    }
    return buffer;
}
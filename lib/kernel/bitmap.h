#pragma once
#include "klib.h"
typedef struct Bitmap {
    uint32_t byte_size;
    uint8_t *bits;  
} Bitmap;

int set_bitmap(Bitmap *bmp, uint32_t idx);
int clear_bitmap(Bitmap *bmp, uint32_t idx);
void init_bitmap(Bitmap *bmp);

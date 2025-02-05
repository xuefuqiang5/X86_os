#pragma once
#include "klib.h"
typedef struct Bitmap {
    uint32_t byte_size;
    uint8_t *bits;  
} Bitmap;
#define bool int
#define true 1
#define false 0
int set_one_bit(Bitmap *bmp, uint32_t idx);
int clear_bitmap(Bitmap *bmp, uint32_t idx);
void init_bitmap(Bitmap *bmp);
bool bitmap_test(Bitmap *bmp, uint32_t idx);
int set_bits(Bitmap *bmp, uint32_t cnt);
#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define false 0 
#define true 1
typedef struct Bitmap {
    uint32_t byte_size;
    uint8_t *bits;  
} Bitmap;
int set_bitmap(Bitmap *bmp, uint32_t idx);
int clear_bitmap(Bitmap *bmp, uint32_t idx);
void init_bitmap(Bitmap *bmp);
bool bitmap_test(Bitmap *bmp, uint32_t idx);
int set_bitmap(Bitmap *bmp, uint32_t idx){
    if(idx >= bmp -> byte_size * 8){
        return -1;
    }
    uint32_t byte_idx = idx / 8;
    uint8_t i = idx % 8;
    bmp -> bits[byte_idx] |= (0x1 << i);
    return 0;
}

int clear_bitmap(Bitmap *bmp, uint32_t idx){
    if(idx >= bmp -> byte_size * 8){
        return -1;
    }
    uint32_t byte_idx = idx / 8;
    uint8_t i = idx % 8;
    bmp -> bits[byte_idx] &= ~(0x1 << i);
    return 0;
}

void init_bitmap(Bitmap *bmp){
    memset(bmp->bits, 0, bmp->byte_size);
}
bool bitmap_test(Bitmap *bmp, uint32_t idx){
    if(idx >= bmp -> byte_size * 8){
        return false;
    }
    uint32_t byte_idx = idx / 8;
    uint8_t i = idx % 8;
    return (!!(bmp -> bits[byte_idx] & (0x1 << i)));
}
void print_bitmap(Bitmap *bmp){
    for(int i = 0; i < bmp -> byte_size * 8; i++){
        bool flag = bitmap_test(bmp, i);
        printf("%d  ", flag);
    }
    printf("\n");
}
int set_bits(Bitmap *bmp, uint32_t cnt){
    if(cnt > bmp -> byte_size * 8){
        return -1;
    }
    for(int i = 0; i < bmp->byte_size * 8; i++){
        if(bitmap_test(bmp, i) == 1) continue;
        for(int j = i + 1; j < bmp->byte_size * 8; j++){
            if(j - i == cnt){
                for(int k = i; k < j; k++) set_bitmap(bmp, k);
                return i;
            }
            if(bitmap_test(bmp, j) == 1) break;
        }
    }
    return -1;
}
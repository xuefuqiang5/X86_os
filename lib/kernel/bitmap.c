#include "bitmap.h"
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
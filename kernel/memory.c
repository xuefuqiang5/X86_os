#include "klib.h"
Bitmap phycial_bitmap;
Bitmap virtual_bitmap;
void memroy_pool_init(Bitmap * bmp, void *start, uint32_t size){
    memset(start, 0, size);
    bmp -> bits = start;
    bmp -> byte_size = size;
    
}
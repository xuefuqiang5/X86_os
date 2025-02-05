#pragma once
#include "../lib/kernel/klib.h"
void mem_pool_init(uint32_t total_mem);
void mem_init();
#define GET_PDE(vaddr) (((vaddr) >> 22) & 0x3ff)
#define GET_PTE(vaddr) (((vaddr) >> 12) & 0x3ff)
#define  PG_P_1   1     // 页表项或页目录项存在属性位 
#define  PG_P_0   0     // 页表项或页目录项存在属性位 
#define  PG_RW_R  0     // R/W 属性位值，读/执行 
#define  PG_RW_W  2    // R/W 属性位值，读/写/执行 
#define  PG_US_S  0     // U/S 属性位值，系统级 
#define  PG_US_U  4     // U/S 属性位值，用户级 


typedef struct vir_memory_pool{
    uint32_t addr_start;
    Bitmap vir_bitmap;
}Vpl;
#define bitmap_base 0xc009a000
typedef struct phy_memory_pool{
    uint32_t addr_start;
    Bitmap phy_bitmap;
    uint32_t pool_size;
}Ppl;

enum pool_flags { 
    PF_KERNEL = 1,    
    PF_USER = 2       
}; 
void *vir_allocate(uint32_t cnt, enum pool_flags pool_flag);
void *phy_allocate(Ppl *pool);
void page_register(void *vaddr, void *paddr);
void* page_allocate(uint32_t cnt, enum pool_flags pool_flag);
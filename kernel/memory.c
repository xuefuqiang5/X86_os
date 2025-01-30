#include "memory.h"
extern char _BSS_END;
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
Vpl vir_ker_pool, vir_usr_pool;
Ppl phy_ker_pool, phy_usr_pool;
/* phy 的开始地址是 0x100000 + 页目录表大小（1） + 内核页表的大小（255） 
 * 之后的空闲空间 ker 与 usr 各分一半
 * phy kernel addr start 的位置是kernel free 的开始位置
 * phy use addr start 的位置是 use free 的开始位置
 * phy kernel bits 的位置是mem_bits标识的地方
 * phy usr bits 的位置是紧跟在phy kernel bits 位置的后面
*/
void mem_pool_init(uint32_t total_mem){
    uint32_t used_mem = 0 ;
    uint32_t free_mem = 0 ;
    uint32_t phy_ker_pool_base = 0x00;
    uint32_t phy_usr_pool_base = 0x00;
    uint32_t phy_ker_bmp_start = 0;
    uint32_t phy_usr_bmp_start = 0;
    uint32_t phy_ker_size = 0;
    uint32_t phy_usr_size = 0;
    uint32_t vir_ker_bmp_start = 0;
    uint32_t heap_base = 0;
    uint32_t vir_usr_bmp_start = 0;
    used_mem = PAGE_SIZE + 256 * PAGE_SIZE;
    free_mem = total_mem - used_mem;
    phy_ker_size = free_mem / 2;
    phy_usr_size = free_mem - phy_ker_size;
    phy_ker_pool_base = used_mem;
    phy_usr_pool_base = phy_ker_pool_base + phy_ker_size;
    uint32_t ker_bitmap_byte_size = phy_ker_size / PAGE_SIZE / 8;
    uint32_t usr_bitmap_byte_size = phy_usr_size / PAGE_SIZE / 8; 
    phy_ker_bmp_start =(void *) bitmap_base;
    phy_usr_bmp_start = phy_ker_bmp_start + ker_bitmap_byte_size;

    put_str("Used Memory: 0x");
    put_int_hex(used_mem);
    put_str(" bytes\n");
    put_str("Free Memory: 0x");
    put_int_hex(free_mem);
    put_str(" bytes\n\n");

    
    phy_ker_pool.addr_start = phy_ker_pool_base;
    phy_ker_pool.pool_size = phy_ker_size;
    phy_ker_pool.phy_bitmap.bits = (void *)phy_ker_bmp_start;
    phy_ker_pool.phy_bitmap.byte_size = ker_bitmap_byte_size;
    init_bitmap(&phy_ker_pool.phy_bitmap);
    
    
    phy_usr_pool.addr_start = phy_usr_pool_base;
    phy_usr_pool.pool_size = phy_usr_size;
    phy_usr_pool.phy_bitmap.bits = (void *)phy_usr_bmp_start;
    phy_usr_pool.phy_bitmap.byte_size = usr_bitmap_byte_size;
    init_bitmap(&phy_usr_pool.phy_bitmap);
    
    vir_ker_bmp_start = phy_usr_bmp_start + usr_bitmap_byte_size;
    heap_base = PAGE_ALIGN_UP(vir_ker_bmp_start + ker_bitmap_byte_size);
    vir_ker_pool.addr_start = heap_base;
    vir_ker_pool.vir_bitmap.byte_size = ker_bitmap_byte_size;
    vir_ker_pool.vir_bitmap.bits = (void *) vir_ker_bmp_start;
    init_bitmap(&vir_ker_pool.vir_bitmap);
 
}
void print_vpl(Vpl *vpl) {
    put_str("Vpl.addr_start: 0x\0");
    put_int_hex(vpl->addr_start);  // 打印 addr_start

    put_str("\nVpl.vir_bitmap.byte_size: 0x\0");
    put_int_hex(vpl->vir_bitmap.byte_size);  // 打印 Bitmap 的字节大小

    put_str("\nVpl.vir_bitmap.bits: 0x\0");
    put_int_hex((uint32_t)vpl->vir_bitmap.bits);  // 打印 bits 指针的地址
}
void print_ppl(Ppl *ppl) {
    put_str("\nPpl.addr_start: 0x\0");
    put_int_hex(ppl->addr_start);  // 打印 addr_start

    put_str("\nPpl.phy_bitmap.byte_size: 0x\0");
    put_int_hex(ppl->phy_bitmap.byte_size);  // 打印 Bitmap 的字节大小

    put_str("\nPpl.phy_bitmap.bits: 0x\0");
    put_int_hex((uint32_t)ppl->phy_bitmap.bits);  // 打印 bits 指针的地址

    put_str("\nPpl.pool_size: 0x\0");
    put_int_hex(ppl->pool_size);  // 打印内存池大小
}
void mem_init() { 
    put_str("mem_init start\n\0"); 
    uint32_t mem_bytes_total = 0x02000000; 
    mem_pool_init(mem_bytes_total);        // 初始化内存池 
    put_str("mem_init done\n\0"); 
}
void debug_mem_pool_init(uint32_t total_mem) {
    // ... 变量定义保持不变 ...
    uint32_t used_mem = 0 ;
    uint32_t free_mem = 0 ;
    uint32_t phy_ker_pool_base = 0x00;
    uint32_t phy_usr_pool_base = 0x00;
    uint32_t phy_ker_bmp_start = 0;
    uint32_t phy_usr_bmp_start = 0;
    uint32_t phy_ker_size = 0;
    uint32_t phy_usr_size = 0;
    uint32_t vir_ker_bmp_start = 0;
    uint32_t heap_base = 0;
    uint32_t vir_usr_bmp_start = 0;
    // 1. 打印总内存信息
    put_str("===== Memory Pool Initialization =====\n");
    put_str("Total Memory: 0x");
    put_int_hex(total_mem);
    put_str(" bytes\n");  // 手动添加换行和结束符

    used_mem = PAGE_SIZE + 256 * PAGE_SIZE;
    free_mem = total_mem - used_mem;

    // 2. 打印已用/空闲内存
    put_str("Used Memory: 0x");
    put_int_hex(used_mem);
    put_str(" bytes\n");
    put_str("Free Memory: 0x");
    put_int_hex(free_mem);
    put_str(" bytes\n\n");

    phy_ker_size = free_mem / 2;
    phy_usr_size = free_mem - phy_ker_size;

    // 3. 打印物理内存池划分
    put_str("---- Physical Memory Division ----\n");
    put_str("Kernel Phy Size: 0x");
    put_int_hex(phy_ker_size);
    put_str(" bytes\n");
    put_str("User Phy Size: 0x");
    put_int_hex(phy_usr_size);
    put_str(" bytes\n\n");

    phy_ker_pool_base = used_mem;
    phy_usr_pool_base = phy_ker_pool_base + phy_ker_size;

    // 4. 打印物理池基地址
    put_str("Kernel Phy Pool Base: 0x");
    put_int_hex(phy_ker_pool_base);
    put_str("\nUser Phy Pool Base: 0x");
    put_int_hex(phy_usr_pool_base);
    put_str("\n\n");

    uint32_t ker_bitmap_byte_size = phy_ker_size / PAGE_SIZE / 8;
    uint32_t usr_bitmap_byte_size = phy_usr_size / PAGE_SIZE / 8;

    // 5. 打印位图信息
    put_str("---- Bitmap Information ----\n");
    put_str("Kernel Bitmap Size: 0x");
    put_int_hex(ker_bitmap_byte_size);
    put_str(" bytes\n");
    put_str("User Bitmap Size: 0x");
    put_int_hex(usr_bitmap_byte_size);
    put_str(" bytes\n\n");

    phy_ker_bmp_start = (uint32_t)bitmap_base;  // 强制转换为uint32_t地址
    phy_usr_bmp_start = phy_ker_bmp_start + ker_bitmap_byte_size;

    // 6. 打印位图物理地址
    put_str("Kernel Bitmap Start: 0x");
    put_int_hex(phy_ker_bmp_start);
    put_str("\nUser Bitmap Start: 0x");
    put_int_hex(phy_usr_bmp_start);
    put_str("\n\n");

    // 初始化内核物理内存池
    phy_ker_pool.addr_start = phy_ker_pool_base;
    phy_ker_pool.pool_size = phy_ker_size;
    phy_ker_pool.phy_bitmap.bits = (void*)phy_ker_bmp_start;
    phy_ker_pool.phy_bitmap.byte_size = ker_bitmap_byte_size;
    init_bitmap(&phy_ker_pool.phy_bitmap);

    // 7. 打印内核物理池信息
    put_str("---- Kernel Physical Pool ----\n");
    put_str("Start: 0x");
    put_int_hex(phy_ker_pool.addr_start);
    put_str("\nSize: 0x");
    put_int_hex(phy_ker_pool.pool_size);
    put_str("\nBitmap Addr: 0x");
    put_int_hex((uint32_t)phy_ker_pool.phy_bitmap.bits);
    put_str("\nBitmap Size: 0x");
    put_int_hex(phy_ker_pool.phy_bitmap.byte_size);
    put_str("\n\n");

    // 初始化用户物理内存池（类似内核部分，略）
    // ...

    vir_ker_bmp_start = phy_usr_bmp_start + usr_bitmap_byte_size;
    heap_base = PAGE_ALIGN_UP(vir_ker_bmp_start + ker_bitmap_byte_size);

    // 8. 打印虚拟池信息
    put_str("---- Virtual Kernel Pool ----\n");
    put_str("Heap Base: 0x");
    put_int_hex(heap_base);
    put_str("\nBitmap Start: 0x");
    put_int_hex(vir_ker_bmp_start);
    put_str("\nBitmap Size: 0x");
    put_int_hex(ker_bitmap_byte_size);
    put_str("\n\n");

    // 初始化虚拟内存池
    vir_ker_pool.addr_start = heap_base;
    vir_ker_pool.vir_bitmap.byte_size = ker_bitmap_byte_size;
    vir_ker_pool.vir_bitmap.bits = (void*)vir_ker_bmp_start;
    init_bitmap(&vir_ker_pool.vir_bitmap);

    put_str("===== Memory Pool Init Done =====\n");
}
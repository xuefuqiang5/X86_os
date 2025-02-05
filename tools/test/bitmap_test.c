
#include "bitmap.c"
#define PAGE_SIZE 4096
#define PAGE_ALIGN_UP(x) (((x) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1))
#define PAGE_ALIGN_DOWN(x) ((x) & ~(PAGE_SIZE - 1))

// 函数声明
int set_bitmap(Bitmap *bmp, uint32_t idx);
int clear_bitmap(Bitmap *bmp, uint32_t idx);
void init_bitmap(Bitmap *bmp);
bool bitmap_test(Bitmap *bmp, uint32_t idx);
void print_bitmap(Bitmap *bmp);
int set_bits(Bitmap *bmp, uint32_t cnt);
// 函数实现略（与题目给出代码相同）

// 测试初始化函数
void test_initialization() {
    Bitmap bmp;
    bmp.byte_size = 2;
    bmp.bits = (uint8_t *)malloc(bmp.byte_size);
    init_bitmap(&bmp);
    for (uint32_t i = 0; i < bmp.byte_size * 8; i++) {
        if (bitmap_test(&bmp, i)) {
            printf("Test initialization failed at bit %u\n", i);
            free(bmp.bits);
            return;
        }
    }
    printf("Initialization test passed.\n");
    free(bmp.bits);
}

// 测试设置位
void test_set_bit() {
    Bitmap bmp;
    bmp.byte_size = 1;
    bmp.bits = (uint8_t *)malloc(bmp.byte_size);
    init_bitmap(&bmp);

    set_bitmap(&bmp, 3);
    if (!bitmap_test(&bmp, 3)) {
        printf("Set bit 3 failed.\n");
        free(bmp.bits);
        return;
    }
    for (uint32_t i = 0; i < 8; i++) {
        if (i != 3 && bitmap_test(&bmp, i)) {
            printf("Set bit 3 affected bit %u\n", i);
            free(bmp.bits);
            return;
        }
    }
    printf("Set bit test passed.\n");
    free(bmp.bits);
}

// 测试清除位
void test_clear_bit() {
    Bitmap bmp;
    bmp.byte_size = 1;
    bmp.bits = (uint8_t *)malloc(bmp.byte_size);
    init_bitmap(&bmp);

    set_bitmap(&bmp, 5);
    clear_bitmap(&bmp, 5);
    if (bitmap_test(&bmp, 5)) {
        printf("Clear bit 5 failed.\n");
        free(bmp.bits);
        return;
    }
    for (uint32_t i = 0; i < 8; i++) {
        if (bitmap_test(&bmp, i)) {
            printf("Clear bit 5 affected bit %u\n", i);
            free(bmp.bits);
            return;
        }
    }
    printf("Clear bit test passed.\n");
    free(bmp.bits);
}

// 测试越界访问
void test_out_of_bounds() {
    Bitmap bmp;
    bmp.byte_size = 2;
    bmp.bits = (uint8_t *)malloc(bmp.byte_size);
    init_bitmap(&bmp);

    if (set_bitmap(&bmp, 16) != -1) {
        printf("Out of bounds set test failed.\n");
        free(bmp.bits);
        return;
    }
    if (clear_bitmap(&bmp, 16) != -1) {
        printf("Out of bounds clear test failed.\n");
        free(bmp.bits);
        return;
    }
    printf("Out of bounds test passed.\n");
    free(bmp.bits);
}

// 测试边界条件
void test_boundary_conditions() {
    Bitmap bmp;
    bmp.byte_size = 2;
    bmp.bits = (uint8_t *)malloc(bmp.byte_size);
    init_bitmap(&bmp);

    if (set_bitmap(&bmp, 15) != 0 || !bitmap_test(&bmp, 15)) {
        printf("Set bit 15 failed.\n");
        free(bmp.bits);
        return;
    }
    if (clear_bitmap(&bmp, 15) != 0 || bitmap_test(&bmp, 15)) {
        printf("Clear bit 15 failed.\n");
        free(bmp.bits);
        return;
    }
    printf("Boundary conditions test passed.\n");
    free(bmp.bits);
}

// 测试混合操作
void test_multiple_operations() {
    Bitmap bmp;
    bmp.byte_size = 2;
    bmp.bits = (uint8_t *)malloc(bmp.byte_size);
    init_bitmap(&bmp);

    set_bitmap(&bmp, 0);
    set_bitmap(&bmp, 3);
    set_bitmap(&bmp, 7);
    set_bitmap(&bmp, 9);
    if (!bitmap_test(&bmp, 0) || !bitmap_test(&bmp, 3) || 
        !bitmap_test(&bmp, 7) || !bitmap_test(&bmp, 9)) {
        printf("Multiple set failed.\n");
        free(bmp.bits);
        return;
    }
    clear_bitmap(&bmp, 3);
    if (bitmap_test(&bmp, 3) || !bitmap_test(&bmp, 0) || 
        !bitmap_test(&bmp, 7) || !bitmap_test(&bmp, 9)) {
        printf("Multiple clear failed.\n");
        free(bmp.bits);
        return;
    }
    printf("Multiple operations test passed.\n");
    free(bmp.bits);
}
void test_set_bits(){
    Bitmap bmp;
    bmp.byte_size = 2;
    bmp.bits = (uint8_t *)malloc(bmp.byte_size);
    init_bitmap(&bmp);
    set_bits(&bmp, 3);
    clear_bitmap(&bmp, 1);
    set_bits(&bmp,3);
    clear_bitmap(&bmp, 2);
    set_bits(&bmp, 5);
    print_bitmap(&bmp);
    free(bmp.bits);
}
#define GET_PDE(vaddr) (((vaddr) >> 22) & 0x3ff)
#define GET_PTE(vaddr) (((vaddr) >> 12) & 0x3ff)
int main() {
    uint32_t vaddr = 0xc0101000;
    uint32_t *a = GET_PDE((uint32_t) vaddr) << 12;
    printf("%p\n", a);
    uint32_t *pde = (GET_PDE((uint32_t) vaddr) << 12) | 0xffc00000;
    uint32_t *pte = (uint32_t)pde + (GET_PTE((uint32_t) vaddr) << 2);
    printf("PDE: %p\n", pde);
    printf("PTE: %p\n", pte);
    return 0;
}
#include "../lib/kernel/klib.h"
#include "../kernel/thread.h"
#define DESC_WRITABLE 0x2
#define DESC_READABLE 0x2

#define DESC_TSS 0x0
#define DESC_TSS32 0x9

#define DESC_DPL_0 0x0
#define DESC_DPL_1 0x20
#define DESC_DPL_2 0x40
#define DESC_DPL_3 0x60

#define DESC_PRESENT 0x80

#define DESC_DB 0x40
#define DESC_G 0x80

#define GDT_TSS			4	
struct tss {
    uint16_t backlink;       // 前一个任务的TSS链接
    uint16_t f1;             // 保留字段
    uint32_t* esp0;           // 栈指针（Ring 0）
    uint16_t ss0;            // 段选择子（Ring 0）
    uint16_t f2;             // 保留字段
    uint32_t* esp1;           // 栈指针（Ring 1）
    uint16_t ss1;            // 段选择子（Ring 1）
    uint16_t f3;             // 保留字段
    uint32_t* esp2;           // 栈指针（Ring 2）
    uint16_t ss2;            // 段选择子（Ring 2）
    uint16_t f4;             // 保留字段
    uint32_t cr3;            // CR3寄存器（页目录基地址）
    uint32_t eip;            // 指令指针（EIP）
    uint32_t eflags;         // 标志寄存器（EFLAGS）
    uint32_t eax;            // 通用寄存器（EAX）
    uint32_t ecx;            // 通用寄存器（ECX）
    uint32_t edx;            // 通用寄存器（EDX）
    uint32_t ebx;            // 通用寄存器（EBX）
    uint32_t esp;            // 通用寄存器（ESP）
    uint32_t ebp;            // 通用寄存器（EBP）
    uint32_t esi;            // 通用寄存器（ESI）
    uint32_t edi;            // 通用寄存器（EDI）
    uint16_t es;             // 段选择子（ES）
    uint16_t f5;             // 保留字段
    uint16_t cs;             // 段选择子（CS）
    uint16_t f6;             // 保留字段
    uint16_t ss;             // 段选择子（SS）
    uint16_t f7;             // 保留字段
    uint16_t ds;             // 段选择子（DS）
    uint16_t f8;             // 保留字段
    uint16_t fs;             // 段选择子（FS）
    uint16_t f9;             // 保留字段
    uint16_t gs;             // 段选择子（GS）
    uint16_t f10;            // 保留字段
    uint16_t ldt;            // LDT选择子
    uint16_t t;              // T标志
    uint16_t iobase;         // I/O位图基地址
};
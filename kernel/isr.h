#pragma once
#include "../lib/kernel/klib.h"
#include "thread.h"
#include "pic.h"
#include "idt.h"
void general_program();
extern void *isr_entry_table[33];
static flag = 0;
typedef void (*isr_func)(void);
#define ZERO_ACTION do { asm volatile("pushl $0"); } while (0)
#define ERROR_ACTION do { asm volatile("nop"); } while (0)
#define CONCAT(X, Y) X##Y
void init_isr_table();
#define INIT_ISR(vecnum, error_code) \
    do { \
        CONCAT(ISR_, vecnum): \
        if ((error_code) == 0) { \
            ZERO_ACTION; \
        } else { \
            ERROR_ACTION; \
        } \
        asm volatile("push %ds"); \
        asm volatile("push %es"); \
        asm volatile("push %fs"); \
        asm volatile("push %gs"); \
        asm volatile ("pusha\n\t" ::: "memory");   \
        out8(0xa0, 0x20); \
        out8(0x20, 0x20); \
        asm volatile("push %0" : : "r" (vecnum) : "memory"); \
        general_program();\
    } while (0)

#define EXIT_ISR()               \
    do{                          \
        asm volatile ("add $4, %esp");      \
        asm volatile("popa");    \
        asm volatile("pop %gs");  \
        asm volatile("pop %fs");  \
        asm volatile("pop %es");  \
        asm volatile("pop %ds");  \
        asm volatile("add $4, %esp");\
    }while(0)

#define ISR_FUNC(vecnum, error_code)\
    do { \
        INIT_ISR(vecnum, error_code);\
        EXIT_ISR(); \
        if(flag == 0) {isr_entry_table[vecnum] = &&CONCAT(ISR_, vecnum);} \
        else {asm volatile("iret");} \
    }while (0)
    
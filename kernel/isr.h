#pragma once
#include "../lib/kernel/klib.h"
#include "thread.h"
#include "pic.h"
#include "idt.h"
void general_program(uint32_t vecnum);
//extern void *isr_entry_table[33];
extern void *intr_entry_table[33];
static int flag = 0;
typedef void (*isr_func)(void);
extern void* idt_table[33];
#define CONCAT(X, Y) X##Y
void init_idt_table();
//void init_isr_table();
void clock_interrupt();
void register_intr_handler(uint32_t vecnum, isr_func func);

    
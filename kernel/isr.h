#pragma once
#include "../lib/kernel/klib.h"
#include "thread.h"
#include "pic.h"
#include "idt.h"
void general_program();
//extern void *isr_entry_table[33];
extern void *intr_entry_table[33];
static int flag = 0;
typedef void (*isr_func)(void);
#define ZERO_ACTION do { asm volatile("pushl $0"); } while (0)
#define ERROR_ACTION do { asm volatile("nop"); } while (0)
#define CONCAT(X, Y) X##Y
//void init_isr_table();

    
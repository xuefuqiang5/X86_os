#pragma once 
#include "idt.h"
#include "isr.h"
#include "pic.h"
#include "memory.h"
#include "timer.h"
#include "thread.h"
#include "semaphore.h"
#include "console.h"
extern char _BSS_END;
extern void *intr_entry_table[IDT_DESC_CNT];
extern void *idt_table[IDT_DESC_CNT];
void init_all();
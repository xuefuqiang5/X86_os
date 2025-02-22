#pragma once 
#include "../lib/kernel/klib.h"
#include "thread.h"
#include "semaphore.h"
void console_init();
void console_acquire(); 
void console_release();
void console_put_str(char* str);
void console_put_char(uint8_t char_asci);
void console_put_int(uint32_t num); 

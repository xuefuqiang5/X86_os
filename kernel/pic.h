#pragma once
#include "../lib/kernel/klib.h"
void pic_init(void);
void pic_sendeoi(int irq);
void pic_setmask(int irq);
void pic_clearmask(int irq);
#pragma once
#include <stdint.h>
void out8(uint16_t port, uint8_t val);
void out16(uint16_t port, uint16_t val);
void out32(uint16_t port, uint32_t val);
uint8_t in8(uint16_t port);
uint16_t in16(uint16_t port);
uint32_t in32(uint16_t port);
void ex_write(uint16_t old_pos, uint16_t new_pos, uint16_t backgroud);
void write_one_char(uint16_t pos, char c);
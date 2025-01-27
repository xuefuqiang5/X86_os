#pragma once
#include <stdint.h>
void out8(uint16_t port, uint8_t val);
void out16(uint16_t port, uint16_t val);
void out32(uint16_t port, uint32_t val);
uint8_t in8(uint16_t port);
uint16_t in16(uint16_t port);
uint32_t in32(uint16_t port);
void lidt(void *addr);
void ex_write(uint16_t old_pos, uint16_t new_pos, uint16_t backgroud);
void write_one_char(uint16_t pos, char c);
#define VIDEO_SELECTOR 0x18
void set_cursor_pos(uint16_t cursor);
void write_into(uint16_t cursor, char c);
void roll_screen();
void clear();
void put_str(char *s);
void put_int_hex(uint32_t num);
void put_char(char c);
void put_int_dec(uint32_t num);
typedef enum {
    CHAR_TAB = '\t',
    CHAR_NEWLINE = '\n',
    CHAR_BACKSPACE = '\b',
    CHAR_CARRIAGE_RETURN = '\r',
    CHAR_BACKSLASH = '\\'
}special_char;
void _assert(char *expression, char *_file, int _line);
#ifdef NDEBUG 
    #define assert(expression) ((void) 0)
#else 
    #define assert(expression) ((void)(\
        (!!(expression)) || \
        (_assert(#expression,__FILE__, (unsigned)(__LINE__)), 0)))

#endif
#define EFLAGS_IF   0x00000200
enum intr_status {             
    INTR_OFF = 0x00,                   
    INTR_ON = EFLAGS_IF                   
}; 
int intr_enable();
int intr_disable();
#pragma once 
#define VIDEO_SELECTOR 0x18
#include "port.h"
void set_cursor_pos(uint16_t cursor);
void write_into(uint16_t cursor, char c);
void roll_screen();
typedef enum {
    CHAR_TAB = '\t',
    CHAR_NEWLINE = '\n',
    CHAR_BACKSPACE = '\b',
    CHAR_CARRIAGE_RETURN = '\r',
    CHAR_BACKSLASH = '\\'

} SpecialChar;
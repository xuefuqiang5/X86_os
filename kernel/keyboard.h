#pragma once
#include "../lib/kernel/klib.h"
#include "ioqueue.h"
struct scanf2ascii{
    uint8_t make_code;
    uint8_t break_code;
    uint8_t asscii;
};
struct shift_map{
    uint8_t orignal;
    uint8_t result;
};
extern const struct scanf2ascii key_mapping_table[256];
extern const struct shift_map shift_mapping_table[];
extern struct ioqueue keyboard_buf;
typedef struct {
    uint8_t caps_lock    : 1;  // Caps Lock 是否激活
    uint8_t num_lock     : 1;  // Num Lock 是否激活
    uint8_t left_shift   : 1;  // 左 Shift 是否按下
    uint8_t right_shift  : 1;  // 右 Shift 是否按下
    uint8_t left_ctrl    : 1;  // 左 Ctrl 是否按下
    uint8_t right_ctrl   : 1;  // 右 Ctrl 是否按下（需扩展键支持）
    uint8_t left_alt     : 1;  // 左 Alt 是否按下
    uint8_t right_alt    : 1;  // 右 Alt 是否按下（需扩展键支持）
} ModifierFlags;

// 键盘宏定义（根据标准扫描码规范）
#define CAPS_LOCK_MAKE    0x3A
#define CAPS_LOCK_BREAK  (CAPS_LOCK_MAKE | 0x80)

#define LEFT_SHIFT_MAKE   0x2A
#define LEFT_SHIFT_BREAK  (LEFT_SHIFT_MAKE | 0x80)

#define RIGHT_SHIFT_MAKE  0x36
#define RIGHT_SHIFT_BREAK (RIGHT_SHIFT_MAKE | 0x80)

#define LEFT_CTRL_MAKE    0x1D
#define LEFT_CTRL_BREAK  (LEFT_CTRL_MAKE | 0x80)

#define LEFT_ALT_MAKE    0x38
#define LEFT_ALT_BREAK  (LEFT_ALT_MAKE | 0x80)

#define NUM_LOCK_MAKE    0x45
#define NUM_LOCK_BREAK  (NUM_LOCK_MAKE | 0x80)

extern ModifierFlags modify_key_status;
void change_key_status(uint8_t code);
uint8_t get_shift_char(uint8_t c);
void init_keyboard();


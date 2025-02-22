#pragma once
#include "../lib/kernel/klib.h"
struct scanf2ascii{
    uint8_t make_code;
    uint16_t break_code;
    uint8_t asscii;
};
extern struct scanf2ascii key_mapping_table[256];


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
enum ModifierKey {
    CAPS_LOCK    = 0x58,   // Caps Lock
    LEFT_SHIFT   = 0x12,   // 左 Shift
    RIGHT_SHIFT  = 0x59,   // 右 Shift
    LEFT_CTRL    = 0x14,   // 左 Ctrl
    RIGHT_CTRL   = 0xE014, // 右 Ctrl（扩展键，需结合 0xE0 前缀）
    LEFT_ALT     = 0x11,   // 左 Alt
    RIGHT_ALT    = 0xE011, // 右 Alt（扩展键，需结合 0xE0 前缀）
    NUM_LOCK     = 0x77    // Num Lock
};
extern ModifierFlags modify_key_status;
void set_modify_flag(enum ModifierKey make_code);

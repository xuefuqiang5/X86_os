#include "keyboard.h"
struct ioqueue keyboard_buf;
const struct scanf2ascii key_mapping_table[256] = {
    [0x00] = {0x00, 0x80, 0},      // 保留

    // ----------- 字母区 -----------
    [0x1E] = {0x1E, 0x9E, 'a'},    // A
    [0x30] = {0x30, 0xB0, 'b'},    // B
    [0x2E] = {0x2E, 0xAE, 'c'},    // C
    [0x20] = {0x20, 0xA0, 'd'},    // D
    [0x12] = {0x12, 0x92, 'e'},    // E
    [0x21] = {0x21, 0xA1, 'f'},    // F
    [0x22] = {0x22, 0xA2, 'g'},    // G
    [0x23] = {0x23, 0xA3, 'h'},    // H
    [0x17] = {0x17, 0x97, 'i'},    // I
    [0x24] = {0x24, 0xA4, 'j'},    // J
    [0x25] = {0x25, 0xA5, 'k'},    // K
    [0x26] = {0x26, 0xA6, 'l'},    // L
    [0x32] = {0x32, 0xB2, 'm'},    // M
    [0x31] = {0x31, 0xB1, 'n'},    // N
    [0x18] = {0x18, 0x98, 'o'},    // O
    [0x19] = {0x19, 0x99, 'p'},    // P
    [0x10] = {0x10, 0x90, 'q'},    // Q
    [0x13] = {0x13, 0x93, 'r'},    // R
    [0x1F] = {0x1F, 0x9F, 's'},    // S
    [0x14] = {0x14, 0x94, 't'},    // T
    [0x16] = {0x16, 0x96, 'u'},    // U
    [0x2F] = {0x2F, 0xAF, 'v'},    // V
    [0x11] = {0x11, 0x91, 'w'},    // W
    [0x2D] = {0x2D, 0xAD, 'x'},    // X
    [0x15] = {0x15, 0x95, 'y'},    // Y
    [0x2C] = {0x2C, 0xAC, 'z'},    // Z

    // ----------- 数字键 -----------
    [0x02] = {0x02, 0x82, '1'},    // 1
    [0x03] = {0x03, 0x83, '2'},    // 2
    [0x04] = {0x04, 0x84, '3'},    // 3
    [0x05] = {0x05, 0x85, '4'},    // 4
    [0x06] = {0x06, 0x86, '5'},    // 5
    [0x07] = {0x07, 0x87, '6'},    // 6
    [0x08] = {0x08, 0x88, '7'},    // 7
    [0x09] = {0x09, 0x89, '8'},    // 8
    [0x0A] = {0x0A, 0x8A, '9'},    // 9
    [0x0B] = {0x0B, 0x8B, '0'},    // 0

    // ----------- 符号键 -----------
    [0x29] = {0x29, 0xA9, '`'},    // `
    [0x0C] = {0x0C, 0x8C, '-'},    // -
    [0x0D] = {0x0D, 0x8D, '='},    // =
    [0x1A] = {0x1A, 0x9A, '['},    // [
    [0x1B] = {0x1B, 0x9B, ']'},    // ]
    [0x2B] = {0x2B, 0xAB, '\\'},   
    [0x27] = {0x27, 0xA7, ';'},    // ;
    [0x28] = {0x28, 0xA8, '\''},   // '
    [0x33] = {0x33, 0xB3, ','},    // ,
    [0x34] = {0x34, 0xB4, '.'},    // .
    [0x35] = {0x35, 0xB5, '/'},    // /

    // ----------- 控制键 -----------
    [0x1C] = {0x1C, 0x9C, '\n'},   // Enter
    [0x0E] = {0x0E, 0x8E, 0x08},   // Backspace
    [0x0F] = {0x0F, 0x8F, '\t'},   // Tab
    [0x39] = {0x39, 0xB9, ' '},     // Space
    [0x3A] = {0x3A, 0xBA, 0},      // Caps Lock
    [0x2A] = {0x2A, 0xAA, 0},      // 左 Shift
    [0x36] = {0x36, 0xB6, 0},      // 右 Shift
    [0x1D] = {0x1D, 0x9D, 0},      // 左 Ctrl
    [0x38] = {0x38, 0xB8, 0},      // 左 Alt
    [0x45] = {0x45, 0xC5, 0},      // Num Lock

    // ----------- 功能键 -----------
    [0x01] = {0x01, 0x81, 0x1B},   // Esc
    [0x3B] = {0x3B, 0xBB, 0},      // F1
    [0x3C] = {0x3C, 0xBC, 0},      // F2
    [0x3D] = {0x3D, 0xBD, 0},      // F3
    [0x3E] = {0x3E, 0xBE, 0},      // F4
    [0x3F] = {0x3F, 0xBF, 0},      // F5
    [0x40] = {0x40, 0xC0, 0},      // F6
    [0x41] = {0x41, 0xC1, 0},      // F7
    [0x42] = {0x42, 0xC2, 0},      // F8
    [0x43] = {0x43, 0xC3, 0},      // F9
    [0x44] = {0x44, 0xC4, 0},      // F10
    [0x57] = {0x57, 0xD7, 0},      // F11
    [0x58] = {0x58, 0xD8, 0},      // F12

    // ----------- 小键盘 -----------
    [0x52] = {0x52, 0xD2, '0'},    // 0
    [0x4F] = {0x4F, 0xCF, '1'},    // 1
    [0x50] = {0x50, 0xD0, '2'},    // 2
    [0x51] = {0x51, 0xD1, '3'},    // 3
    [0x4B] = {0x4B, 0xCB, '4'},    // 4
    [0x4C] = {0x4C, 0xCC, '5'},    // 5
    [0x4D] = {0x4D, 0xCD, '6'},    // 6
    [0x47] = {0x47, 0xC7, '7'},    // 7
    [0x48] = {0x48, 0xC8, '8'},    // 8
    [0x49] = {0x49, 0xC9, '9'},    // 9
    [0x37] = {0x37, 0xB7, '*'},    // *
    [0x4E] = {0x4E, 0xCE, '+'},    // +
    [0x4A] = {0x4A, 0xCA, '-'},    // -
    [0x53] = {0x53, 0xD3, '.'},    // .
};
/* const struct shift_map shift_mapping_table[] = {
    {'1', '!'},    // Shift + 1
    {'2', '@'},    // Shift + 2
    {'3', '#'},    // Shift + 3
    {'4', '$'},    // Shift + 4
    {'5', '%'},    // Shift + 5
    {'6', '^'},    // Shift + 6
    {'7', '&'},    // Shift + 7
    {'8', '*'},    // Shift + 8
    {'9', '('},    // Shift + 9
    {'0', ')'},   // Shift + 0
    {'-', '_'},
    {'=', '+'},
    {'`', '~'},
    {',', '<'},
    {'.', '>'},
    {'[', '{'},
    {']', '}'},   
    {';', ':'},   
    {'/', '?'},
    {'\\', '|'},  
    {'\'', '"'}   
}; */
uint8_t shift_char(uint8_t c) {
    switch(c) {
        case '1': return '!';    // Shift + 1
        case '2': return '@';    // Shift + 2
        case '3': return '#';    // Shift + 3
        case '4': return '$';    // Shift + 4
        case '5': return '%';    // Shift + 5
        case '6': return '^';    // Shift + 6
        case '7': return '&';    // Shift + 7
        case '8': return '*';    // Shift + 8
        case '9': return '(';    // Shift + 9
        case '0': return ')';    // Shift + 0
        case '-': return '_';    // Shift + -
        case '=': return '+';    // Shift + =
        case '`': return '~';    // Shift + `
        case ',': return '<';    // Shift + ,
        case '.': return '>';    // Shift + .
        case '/': return '?';    // Shift + /
        case '[': return '{';
        case ']': return '}';
        case '\\': return '|';
        case ';': return ':';
        case '\'': return '"';
        default: return '\0';   // 未定义字符
    }
}
ModifierFlags modify_key_status = {0};
void change_key_status(uint8_t code){
    switch (code)
    {
    case CAPS_LOCK_BREAK:
        modify_key_status.caps_lock ^= 1;
        break;
    case NUM_LOCK_BREAK:
        modify_key_status.num_lock ^= 1;
        break;
    case LEFT_SHIFT_MAKE:
        modify_key_status.left_shift = 1;
        break;
    case LEFT_SHIFT_BREAK:
        modify_key_status.left_shift = 0;
        break;
    case LEFT_ALT_MAKE:
        modify_key_status.left_alt = 1;
        break;
    case LEFT_ALT_BREAK:
        modify_key_status.left_alt = 0;
        break;
    case LEFT_CTRL_MAKE:
        modify_key_status.left_ctrl = 1;
        break; 
    case LEFT_CTRL_BREAK: 
        modify_key_status.left_ctrl = 0;
        break;
    case RIGHT_SHIFT_MAKE:
        modify_key_status.right_alt = 1;
        break;
    case RIGHT_SHIFT_BREAK:
        modify_key_status.right_shift = 0;
        break;

    default:
        break;
    }
}
void init_keyboard(){
    register_intr_handler(0x21, keyboard_intr_handler); 
    ioq_init(&keyboard_buf);
    put_str("keyboard has done\n");

}
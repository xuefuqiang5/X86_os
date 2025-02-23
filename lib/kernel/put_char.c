#include "klib.h"
/* void put_char(char c){
    uint8_t cursor_low = 0x00;
    uint8_t cursor_high = 0x00;
    uint16_t cursor = 0x00;
    uint8_t row = 0x00;
    uint8_t col = 0x00;
    asm volatile("movw %%ax , %%gs\r\t"
                : : "a"(VIDEO_SELECTOR)
                );
    out8(0x3d4, 0x0e);  
    cursor_high = in8(0x3d5);
    out8(0x3d4, 0x0f);
    cursor_low= in8(0x3d5);
    cursor = (cursor_high << 8) | cursor_low;
    row = cursor / 80;
    col = cursor % 80;
    switch (c){
        case CHAR_NEWLINE: 
            if(row == 24) {
                roll_screen();
                cursor = 24 * 80;
            } else {cursor = (row + 1) * 80;}
            set_cursor_pos(cursor);
            break;
        case CHAR_CARRIAGE_RETURN:
            cursor = cursor / 80 * 80;
            set_cursor_pos(cursor);
            break;
        case CHAR_BACKSPACE:
            if(col == 0){
                if(row == 0) break;
                cursor = (row - 1) * 80 + 79;
            } else {
                cursor = cursor - 1;
            }
            write_into(cursor, ' ');
            set_cursor_pos(cursor);
            break;
        case CHAR_TAB:
            if(row == 24 && col == 79){
                roll_screen();
                cursor = 24 * 80;
                set_cursor_pos(cursor);
                break;
            }
            if(col < 72) cursor += 8;
            else if(col < 80) cursor = row * 80 + 79;
            else if(col == 80) cursor = (row + 1) * 80;
            set_cursor_pos(cursor);
            break;
        case CHAR_BACKSLASH:
            write_into(cursor, c);
            cursor++;
            if(cursor == 80 * 25){
                roll_screen();
                cursor = 80 * 24;
            }
            set_cursor_pos(cursor);
            break;
        default:
            write_into(cursor, c);
            if(row == 24 && col == 79){
                roll_screen();
                cursor = 24 * 80;
            } else {
                cursor++;
            }
            set_cursor_pos(cursor);
            break;
    }
} */
void put_char(char c) {
    uint16_t cursor;
    asm volatile("movw %%ax, %%gs" : : "a"(VIDEO_SELECTOR));

    // 读取光标位置
    out8(0x3D4, 0x0E);
    uint8_t cursor_high = in8(0x3D5);
    out8(0x3D4, 0x0F);
    uint8_t cursor_low = in8(0x3D5);
    cursor = (cursor_high << 8) | cursor_low;

    switch (c) {
        case CHAR_NEWLINE:
            if (cursor / 80 == 24) {
                roll_screen();
                cursor = 24 * 80;
            } else {
                cursor = (cursor / 80 + 1) * 80;
            }
            break;
            
        case CHAR_CARRIAGE_RETURN:
            cursor = cursor / 80 * 80;
            break;
            
        case CHAR_BACKSPACE:
            if (cursor > 0) {
                cursor--;
                write_into(cursor, ' ');
            }
            break;
            
        case CHAR_TAB: {
            uint8_t new_col = cursor % 80 + 8 - (cursor % 80 % 8);
            if (new_col >= 80) {  // 需要换行
                new_col = 0;
                uint8_t new_row = cursor / 80 + 1;
                
                if (new_row >= 25) {
                    roll_screen();
                    new_row = 24;
                }
                cursor = new_row * 80 + new_col;
            } else {
                cursor = cursor / 80 * 80 + new_col;
            }
            break;
        }
            
        default:
            write_into(cursor, c);
            cursor++;
            
            // 处理屏幕滚动
            if (cursor >= 80 * 25) {
                roll_screen();
                cursor = 80 * 24;
            }
            break;
    }

    set_cursor_pos(cursor);
}



char to_upper(char c) {
    // 检查字符是否为小写字母
    if (c >= 'a' && c <= 'z') {
        return c - 32; // ASCII码偏移转换
    }
    return c; // 非小写字母直接返回原值
}















// 函数还没有被检验正确
void roll_screen(){
    for(uint8_t i = 1; i < 25; i++){
        for(uint8_t j = 0; j < 80; j++){
            uint16_t old_pos = (i * 80 + j) * 2;
            uint16_t new_pos = ((i - 1) * 80 + j) * 2;
            uint16_t backgroud = new_pos + 1;
            ex_write(old_pos, new_pos, backgroud);
        }
    }
    uint16_t cursor = 24 * 80;
    for(uint8_t i = 0; i < 80; i++){
        cursor += 1;
        write_into(cursor, ' ');
    }
}
void set_cursor_pos(uint16_t cursor){
    uint8_t cursor_low = cursor & 0xff;
    uint8_t cursor_high = (cursor >> 8) & 0xff;
    out8(0x3d4, 0x0e);
    out8(0x3d5, cursor_high);
    out8(0x3d4, 0x0f);
    out8(0x3d5, cursor_low);
}
void write_into(uint16_t cursor, char c){
    uint16_t pos = cursor * 2;
    write_one_char(pos, c);
}
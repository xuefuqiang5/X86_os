
#include "klib.h"
void clear(){
    uint16_t cursor = 0;
    for(cursor = 0; cursor < 80 * 25; cursor++){
        write_into(cursor, ' ');
    }
    set_cursor_pos(0);
}
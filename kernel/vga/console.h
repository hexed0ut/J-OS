#ifndef CONSOLE_H
#define CONSOLE_H

#include "cursor.h"
#include "../ps2/driver.h"
#include "../global.h"

void clear_vga_buffer() {
    char* vga = VGA_BUFFER_START;
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        *(vga+(i*2)) = 0;
        *(vga+(i*2)+1) = 0x07;
    }
}

void clear_screen() {
    clear_vga_buffer();
    reset_cursor();
}

void stream_ps2_to_console() {
    // waits for valid input from keyboard driver and writes to console char by char
    char* vga = VGA_BUFFER_START;
    int pos = 0;
    while (1) {
        char key = await_ps2_key(); 
        if (key /*in printables*/) {
            *(vga + pos) = key;
            pos = pos + 2;
            shift_cursor(1);
        }
    }
}

#endif
#ifndef CONSOLE_H
#define CONSOLE_H

#include "cursor.h"
#include "global.h"

void clear_vga_buffer()
{
    char* vga = VGA_BUFFER_START;
    
    for ( int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++ )
    {
        *(vga + (i * 2)) = 0;
        *(vga + (i * 2) + 1) = 0x07;
    }
}

void clear_screen()
{
    clear_vga_buffer();
    reset_cursor();
}

#endif
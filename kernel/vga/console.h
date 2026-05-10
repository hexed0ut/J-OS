#pragma once

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

void push_to_vga( char ch )
{
	if ( ch == '\n' )
	{
		int pos = get_cursor_position();
		shift_cursor( VGA_WIDTH - (pos % VGA_WIDTH) );
		return;
	}

	char* vga = VGA_BUFFER_START;
	int pos = 2 * get_cursor_position();
	*(vga + pos) = ch;
	shift_cursor( 1 );
}

void pop_from_vga()
{
	char* vga = VGA_BUFFER_START;
	int pos = 2 * get_cursor_position();
	char to_pop;

	do
	{
		to_pop = *(vga + pos - 2);
		*(vga + pos - 2) = 0;
		shift_cursor( -1 );
		pos -= 2;
	} while ( to_pop == 0 && (*(vga + pos - 2)) == 0 && (pos / 2) % VGA_WIDTH != 0 );
}
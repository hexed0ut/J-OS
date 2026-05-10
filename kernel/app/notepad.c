#pragma once

#include "ps2/driver.h"
#include "iostream.h"
#include "ds/buffer.h"
#include "vga/console.h"

char notepad_buffer[10000];
char* notepad_head = notepad_buffer;

void stream_ps2_to_notepad_buffer()
{
	while ( 1 )
	{
		char* a = 0xB8100;
		enum keycode key = await_ps2_key_event( 0 );
		if ( key == KEY_LSHIFT_RELEASED ) *a = '+';
		char ch = resolve_keycode_ascii( key );
		if (ch==0) *a = '?'; else *a = '^';

		if ( key == KEY_BACKSPACE_PRESSED )
		{
			pop_from_buffer( notepad_buffer, 0, &notepad_head );
			pop_from_vga();
		}

		if ( key == KEY_ENTER_PRESSED )
		{
			push_to_buffer( notepad_buffer, 0, &notepad_head, '\n' );
			push_to_vga( '\n' );
		}

		if ( !ch ) continue;

		push_to_buffer( notepad_buffer, 0, &notepad_head, ch );
		push_to_vga( ch );
	}
}

void start_notepad()
{
	clear_screen();
	stream_ps2_to_notepad_buffer();
}
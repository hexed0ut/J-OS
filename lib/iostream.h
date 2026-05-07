#pragma once

#include "ps2/driver.h"
#include "vga/cursor.h"
#include "ps2/keymap.h"
#include "character.h"

char resolve_shift( unsigned char ch )
{
	if ( is_alpha( ch ) )
	{
		if ( !CAPSLOCK_ACTIVE ) return to_uppercase( ch );
		else return ch;
	}

	return shift_map[ch];
}

char resolve_keycode( unsigned char keycode )
{
	struct KeyMapValue val = keycode_ascii[keycode];

	if ( val.type == PRINTABLE )
	{
		if ( SHIFT_ACTIVE ) return resolve_shift( val.ascii );

		if ( CAPSLOCK_ACTIVE ) return to_uppercase( val.ascii );

		return val.ascii;
	}

	return 0;
}

void read_input()
{
	char* vga = (char*)VGA_BUFFER_START;
	int pos = 0;
	while ( 1 )
	{
		enum keycode key = await_ps2_key_event( 0 );
		char ch = resolve_keycode( key );
		if ( !ch ) continue;

		*(vga + pos) = ch;
		pos = pos + 2;
		shift_cursor( 1 );
	}
}

void read_key_event() { return; }
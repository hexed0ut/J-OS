#pragma once

#include "ps2/driver.h"
#include "vga/cursor.h"
#include "ps2/keymap.h"
#include "character.h"
#include "iobuff.h"
#include "memory.h"

char resolve_shift( unsigned char ch )
{
	if ( is_alpha( ch ) )
	{
		if ( !CAPSLOCK_ACTIVE ) return to_uppercase( ch );
		else return ch;
	}

	return shift_map[ch];
}

char resolve_keycode_to_ascii( unsigned char keycode )
{
	struct KeyMapValue val = keycode_ascii[keycode];

	if ( val.type == PRINTABLE )
	{
		if ( SHIFT_ACTIVE ) return resolve_shift( val.ascii );

		if ( CAPSLOCK_ACTIVE ) return to_uppercase( val.ascii );

		return val.ascii;
	}

	if ( val.type == NUMPAD )
	{
		if ( NUMLOCK_ACTIVE ) return val.ascii;

		return 0;
	}

	return 0;
}

char resolve_keycode_to_type( unsigned char keycode )
{
	return keycode_ascii[keycode].type;
}

void read_input()
{
	char* vga = (char*)VGA_BUFFER_START;
	int pos = 0;
	while ( 1 )
	{
		enum keycode key = await_ps2_key_event( 0 );
		char ch = resolve_keycode_to_ascii( key );
		if ( !ch ) continue;

		*(vga + pos) = ch;
		pos = pos + 2;
		shift_cursor( 1 );
	}
}

void std_input( char* str )
{
	long length = strlen( std_input_buffer );
	memcpy( std_input_buffer, str, length );
	flush_std_input_buffer();
}

void std_output( char* str )
{
	memcpy( str, std_output_buffer, strlen( str ) );
	strcat( std_output_buffer, '\n' );
	flush_std_output_buffer();
}

void std_output( char* str, char end )
{
	memcpy( str, std_output_buffer, strlen( str ) );
	strcat( std_output_buffer, end );
}

void read_key_event() { return; }
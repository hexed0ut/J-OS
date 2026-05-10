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

char resolve_keycode_ascii( unsigned char keycode )
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
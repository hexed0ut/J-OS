#pragma once

#include "ps2/driver.h"
#include "iostream.h"
#include "ds/buffer.h"
#include "vga/console.h"

char shell_buffer[10000];
char* shell_head = shell_buffer;

enum sh_mode {
	COMMAND_MODE,
	OUTPUT_MODE,
};

char shell_mode = COMMAND_MODE;

void stream_ps2_to_shell_buffer()
{
	while ( 1 )
	{	
		enum keycode key = await_ps2_key_event( 0 );
		char ch = resolve_keycode_ascii( key );
		char* a = 0xB8200;
		*a = ch;

		if ( key == KEY_BACKSPACE_PRESSED)
		{
			if ( *(shell_head-1) == '>' || *(shell_head-1) == '=' ) continue;  // TODO: plz dont take away = and > from users

			pop_from_buffer( shell_buffer, 0, &shell_head );
			pop_from_vga();
		}

		else if ( key == KEY_ENTER_PRESSED ) // TODO: numpad ops and normal ops are same
		{
			if ( shell_mode == COMMAND_MODE )
			{
				push_to_buffer( shell_buffer, 0, &shell_head, '\n' );
				push_to_vga('\n');
				push_to_buffer( shell_buffer, 0, &shell_head, '=' );
				push_to_vga('=');
			}

			else if ( shell_mode == OUTPUT_MODE )
			{
				push_to_buffer( shell_buffer, 0, &shell_head, '\n' );
				push_to_vga('\n');
				push_to_buffer( shell_buffer, 0, &shell_head, '>' );
				push_to_vga('>');
			}

			shell_mode = !shell_mode;
		}

		else if ( !ch ) continue;

		else if ( shell_mode == COMMAND_MODE)
		{
			push_to_buffer( shell_buffer, 0, &shell_head, ch );
			push_to_vga( ch );
		}
	}	
}

void start_shell()
{
	push_to_buffer( shell_buffer, 0, &shell_head, '>' );
	push_to_vga( '>' );
	stream_ps2_to_shell_buffer();
}





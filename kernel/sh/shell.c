#pragma once

#include "ps2/driver.h"
#include "iostream.h"
#include "ds/buffer.h"
#include "global.h"
#include "ps2/keycode.h"
#include "string.h"
#include "process.h"

#define SHELL_BUFFER_SIZE 10000

char  shell_buffer[SHELL_BUFFER_SIZE];
char* buffer_end = shell_buffer;
char* cursor_position = shell_buffer;

void start_shell() { while ( true ) read_eval_print(); }

void read_eval_print()
{
	std_output( "sh +> " );

	char command[IO_BUFFER_SIZE];
	std_input( &command );

	eval_shell_command( command );
}

void shell_input( char* str )
{

}

void push_to_buffer( char* buffer, int buffer_size, char* buffer_end, char* insert_position, char ch )
{
	if ( OVERWRITE_ACTIVE )
	{
		buffer[*insert_position] = ch;
	}
	else
	{
		strcpy( insert_position, insert_position + 1, *buffer_end - *insert_position );
		buffer[*insert_position] = ch;
	}
}
#pragma once

void push_to_buffer( char* buffer, int buffer_size, char** buffer_head, char ch )
{
	**buffer_head = ch;
	*buffer_head += 1;
}

void pop_from_buffer( char* buffer, int buffer_size, char** buffer_head )
{
	*(*buffer_head-1) = 0;
	*buffer_head -= 1;
}
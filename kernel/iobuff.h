#pragma once

#define IO_BUFFER_SIZE 10000

char std_input_buffer[IO_BUFFER_SIZE];
char std_output_buffer[IO_BUFFER_SIZE];

void flush_std_input_buffer()
{
	for ( int i = 0; i < IO_BUFFER_SIZE; i++ )
	{
		std_input_buffer[i] = 0;
	}
}

void flush_std_output_buffer()
{
	for ( int i = 0; i < IO_BUFFER_SIZE; i++ )
	{
		std_output_buffer[i] = 0;
	}
}
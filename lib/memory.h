#pragma once

void memcpy( char* source, char* destination, int size_in_bytes )
{
	char temp[size_in_bytes];
	for ( int i = 0; i < size_in_bytes; i++ )
	{
		temp[i] = *source;
		source += 1;
	}
	for ( int i = 0; i < size_in_bytes; i++ )
	{
		*destination = temp[i];
		destination += 1;
	}
}
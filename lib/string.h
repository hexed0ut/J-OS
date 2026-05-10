#pragma once

#include <stdint-gcc.h>

void strcpy( char* source, char* destination, int size )
{
	char temp[size];
	for ( int i = 0; i < size; i++ )
	{
		temp[i] = *source;
		source += 1;
	}
	for ( int i = 0; i < size; i++ )
	{
		*destination = temp[i];
		destination += 1;
	}
}

bool strcmp( char* str1, char* str2 )
{
	while ( *str1 )
	{
		if ( *str1 != *str2 ) return false;
		*str1++; *str2++;
	}

	return true;
}

uint64_t strlen( char* str )
{
	uint64_t len = 0;

	while ( *str != 0 )
	{
		len++;
		str++;
	}

	return len;
}

void strcat( char* str, char ch )
{
	while ( *str ) str++;
	*str = ch;
}

void strcat( char* str1, char* str2 )
{
	while ( *str1 ) str1++;
	while ( *str2 )
	{
		*str1 = *str2;
		str1++; str2++;
	}
}

#pragma once

#include <stdbool.h>

bool is_alpha( char ch )
{
	return ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z');
}

bool is_uppercase( char ch )
{
	return ('A' <= ch && ch <= 'Z');
}

char to_uppercase( char ch )
{
	if ( is_alpha( ch ) && !is_uppercase( ch ) )
		return ch - 32;

	return ch;
}
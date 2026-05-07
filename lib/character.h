#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdbool.h>

bool is_alpha( char ch )
{
	return ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z');
}

#endif
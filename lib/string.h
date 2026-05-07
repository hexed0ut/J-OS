#ifndef STRING_Hvkh
#define STRING_H

#include "character.h"

char to_uppercase( char ch )
{
	if ( is_alpha( ch ) )
        return ch - 32;
    
    return ch;
}

#endif
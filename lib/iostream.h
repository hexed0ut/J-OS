#ifndef IOSTREAM_H
#define IOSTREAM_H

#include "ps2/driver.h"
#include "vga/cursor.h"
#include "ps2/keymap.h"
#include "string.h"

char resolve_shift( unsigned char key )
{
    if ( is_alpha( key ) )
        return to_uppercase( key );

    return shift_map[key];
}

char resolve_keycode( unsigned char keycode )
{
    if ( keycode_ascii[keycode].type == PRINTABLE )
    {
        if ( SHIFT_ACTIVE )
            return resolve_shift( keycode_ascii[keycode].ascii );

        if ( CAPSLOCK_ACTIVE )
            return to_uppercase( keycode_ascii[keycode].ascii );

        return keycode_ascii[keycode].ascii;
    }
    
    return 0;
}

void read_input()
{
    char* vga = (char*)VGA_BUFFER_START;
    int pos = 0;
    while ( 1 )
    {
        enum keycode key = await_ps2_key_event( 0 );
        char ch = resolve_keycode( key );
        if ( !ch ) continue;

        *(vga + pos) = ch;
        pos = pos + 2;
        shift_cursor( 1 );
    }
}

void read_key_event() { return; }

#endif
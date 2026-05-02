#ifndef DRIVER_H
#define DRIVER_H

#include "keymap.h"
#include "state.c"
#include "scan_code_set_1.h"

unsigned char is_keypress()
{
    return inb( 0x64 ) & 1;
}

char resolve_ps2_key( unsigned char scan_code )
{
    struct KeyMapValue resolved_key = ps2_us_qwerty[scan_code];

    if ( resolved_key.type == PRINTABLE )
    {
        if ( SHIFT_ACTIVE )
        {
            return resolved_key.key - 32;
        }
        else
        {
            return resolved_key.key;
        }
    }

    else if ( resolved_key.type == MODIFIER )
    {
        if ( scan_code == SC_LSHIFT_PRESS || scan_code == SC_RSHIFT_PRESS )
        {
            SHIFT_ACTIVE = 1;
        }
        else if ( scan_code == SC_LSHIFT_RELEASE || scan_code == SC_RSHIFT_RELEASE )
        {
            SHIFT_ACTIVE = 0;
        }
    }
    return 0;
}

char await_ps2_key()
{
    while ( 1 )
    {
        if ( is_keypress() )
        {
            unsigned char scan_code = inb( 0x60 );
            return resolve_ps2_key( scan_code );
        }
    }
}

#endif
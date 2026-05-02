#ifndef DRIVER_H
#define DRIVER_H

#include "keymap.h"
#include "state.c"
#include "scan_code_set_1.h"

char shift_map[128] = {
    ['1'] = '!',['2'] = '@',['3'] = '#',['4'] = '$',['5'] = '%',
    ['6'] = '^',['7'] = '&',['8'] = '*',['9'] = '(',['0'] = ')',

    ['-'] = '_',['='] = '+',['['] = '{',[']'] = '}',['\\'] = '|',
    [';'] = ':',['\''] = '"',[','] = '<',['.'] = '>',['/'] = '?',['`'] = '~',
};

unsigned char is_keypress()
{
    return (inb( 0x64 ) & 1);
}

char resolve_caps( unsigned char key )
{
    if ( key > 96 && key < 123 )
    {
        return key - 32;
    }
    else
    {
        return key;
    }
}

char resolve_shift( unsigned char key )
{
    if ( key > 96 && key < 123 )
    {
        return resolve_caps( key );
    }
    else
    {
        return shift_map[key];
    }
}

char resolve_ps2_key( unsigned char scan_code )
{

    if ( ps2_us_qwerty[scan_code].type == PRINTABLE )
    {
        if ( SHIFT_ACTIVE )
        {
            return resolve_shift( ps2_us_qwerty[scan_code].key );
        }
        else if ( CAPSLOCK_ACTIVE )
        {
            return resolve_caps( ps2_us_qwerty[scan_code].key );
        }
        else
        {
            return ps2_us_qwerty[scan_code].key;
        }
    }

    else if ( ps2_us_qwerty[scan_code].type == MODIFIER )
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

    else if ( ps2_us_qwerty[scan_code].type == LOCK )
    {
        if ( scan_code == SC_CAPSLOCK )
        {
            CAPSLOCK_ACTIVE = !CAPSLOCK_ACTIVE;
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
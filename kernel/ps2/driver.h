#pragma once

#include "scan_code_set_1.h"
#include "os_keycode.h"
#include "global.h"

unsigned char is_keypress()
{
    return inb( 0x64 ) & 1;
}

void update_global_modifier_state( enum keycode key_event )
{
    switch ( key_event )
    {
    case KEY_LSHIFT_PRESSED: case KEY_RSHIFT_PRESSED:
        SHIFT_ACTIVE = 1;
        break;

    case KEY_LSHIFT_RELEASED: case KEY_RSHIFT_RELEASED:
        SHIFT_ACTIVE = 0;
        break;

    case KEY_LCTRL_PRESSED: case KEY_RCTRL_PRESSED:
        CTRL_ACTIVE = 1;
        break;

    case KEY_LCTRL_RELEASED: case KEY_RCTRL_RELEASED:
        CTRL_ACTIVE = 0;
        break;

    case KEY_CAPSLOCK_PRESSED:
        CAPSLOCK_ACTIVE = !CAPSLOCK_ACTIVE;
        break;

    case KEY_NUMLOCK_PRESSED:
        NUMLOCK_ACTIVE = !NUMLOCK_ACTIVE;
        break;
    }
}

enum keycode await_ps2_key_event( unsigned char* source_map )
{
    if ( source_map == 0 )
    {
        source_map = (unsigned char*)&keycode_map;

        while ( 1 )
        {
            if ( is_keypress() )
            {
                unsigned char scan_code = inb( 0x60 );

                if ( scan_code != SC_EXTENDED )
                {
                    enum keycode key_event = source_map[scan_code];
                    update_global_modifier_state( key_event );
                    return key_event;
                }
                else
                    await_ps2_key_event( (unsigned char*)&keycode_map_extended );
            }
        }
    }
}
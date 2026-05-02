#ifndef KEYMAP_H
#define KEYMAP_H

#include "scan_code_set_1.h"
#define NO_DISPLAY 0

enum KeyType
{
    UNDEFINED,
    PRINTABLE,
    MODIFIER,
    LOCK,
    SPECIAL,
    FUNCTION,
    NUMPAD,
    MULTIKEY
};

struct KeyMapValue
{
    unsigned char key;
    enum KeyType type;
};

const struct KeyMapValue ps2_us_qwerty[256] = {
    [SC_1]              = { '1', PRINTABLE }, [SC_2]              = { '2', PRINTABLE }, [SC_3]              = { '3', PRINTABLE },
    [SC_4]              = { '4', PRINTABLE }, [SC_5]              = { '5', PRINTABLE }, [SC_6]              = { '6', PRINTABLE },
    [SC_7]              = { '7', PRINTABLE }, [SC_8]              = { '8', PRINTABLE }, [SC_9]              = { '9', PRINTABLE },
    [SC_0]              = { '0', PRINTABLE }, [SC_MINUS]          = { '-', PRINTABLE }, [SC_EQUAL]          = { '=', PRINTABLE },

    [SC_Q]              = { 'q', PRINTABLE }, [SC_W]              = { 'w', PRINTABLE }, [SC_E]              = { 'e', PRINTABLE },
    [SC_R]              = { 'r', PRINTABLE }, [SC_T]              = { 't', PRINTABLE }, [SC_Y]              = { 'y', PRINTABLE },
    [SC_U]              = { 'u', PRINTABLE }, [SC_I]              = { 'i', PRINTABLE }, [SC_O]              = { 'o', PRINTABLE },
    [SC_P]              = { 'p', PRINTABLE }, [SC_LBRACKET]       = { '[', PRINTABLE }, [SC_RBRACKET]       = { ']', PRINTABLE },

    [SC_A]              = { 'a', PRINTABLE }, [SC_S]              = { 's', PRINTABLE }, [SC_D]              = { 'd', PRINTABLE },
    [SC_F]              = { 'f', PRINTABLE }, [SC_G]              = { 'g', PRINTABLE }, [SC_H]              = { 'h', PRINTABLE },
    [SC_J]              = { 'j', PRINTABLE }, [SC_K]              = { 'k', PRINTABLE }, [SC_L]              = { 'l', PRINTABLE },
    [SC_SEMICOLON]      = { ';', PRINTABLE }, [SC_APOSTROPHE]     = {'\'', PRINTABLE }, [SC_GRAVE]          = { '`', PRINTABLE },

    [SC_Z]              = { 'z', PRINTABLE }, [SC_X]              = { 'x', PRINTABLE }, [SC_C]              = { 'c', PRINTABLE },
    [SC_V]              = { 'v', PRINTABLE }, [SC_B]              = { 'b', PRINTABLE }, [SC_N]              = { 'n', PRINTABLE },
    [SC_M]              = { 'm', PRINTABLE }, [SC_SPACE]          = { ' ', PRINTABLE },

    [SC_BACKSLASH]      = { '\\', PRINTABLE },
    [SC_COMMA]          = { ',',  PRINTABLE },
    [SC_DOT]            = { '.',  PRINTABLE },
    [SC_SLASH]          = { '/',  PRINTABLE },

    [SC_LALT_PRESS]     = { NO_DISPLAY, MODIFIER },
    [SC_LSHIFT_PRESS]   = { NO_DISPLAY, MODIFIER },
    [SC_LSHIFT_RELEASE] = { NO_DISPLAY, MODIFIER },
    [SC_RSHIFT_PRESS]   = { NO_DISPLAY, MODIFIER },
    [SC_RSHIFT_RELEASE] = { NO_DISPLAY, MODIFIER },
    [SC_LCTRL_PRESS]    = { NO_DISPLAY, MODIFIER },

    [SC_NUMLOCK]        = { NO_DISPLAY, LOCK },
    [SC_CAPSLOCK]       = { NO_DISPLAY, LOCK },
    [SC_SCROLLLOCK]     = { NO_DISPLAY, LOCK },

    [SC_ESC]            = { NO_DISPLAY, SPECIAL },
    [SC_TAB]            = { NO_DISPLAY, SPECIAL },
    [SC_ENTER]          = { NO_DISPLAY, SPECIAL },
    [SC_BACKSPACE]      = { NO_DISPLAY, SPECIAL },

    [SC_F1]             = { NO_DISPLAY, FUNCTION },
    [SC_F2]             = { NO_DISPLAY, FUNCTION },
    [SC_F3]             = { NO_DISPLAY, FUNCTION },
    [SC_F4]             = { NO_DISPLAY, FUNCTION },
    [SC_F5]             = { NO_DISPLAY, FUNCTION },
    [SC_F6]             = { NO_DISPLAY, FUNCTION },
    [SC_F7]             = { NO_DISPLAY, FUNCTION },
    [SC_F8]             = { NO_DISPLAY, FUNCTION },
    [SC_F9]             = { NO_DISPLAY, FUNCTION },
    [SC_F10]            = { NO_DISPLAY, FUNCTION },
    [SC_F11]            = { NO_DISPLAY, FUNCTION },
    [SC_F12]            = { NO_DISPLAY, FUNCTION },

    [SC_NUMPAD_STAR]    = { '*', NUMPAD },
    [SC_NUMPAD_7]       = { '7', NUMPAD },
    [SC_NUMPAD_8]       = { '8', NUMPAD },
    [SC_NUMPAD_9]       = { '9', NUMPAD },
    [SC_NUMPAD_MINUS]   = { '-', NUMPAD },
    [SC_NUMPAD_4]       = { '4', NUMPAD },
    [SC_NUMPAD_5]       = { '5', NUMPAD },
    [SC_NUMPAD_6]       = { '6', NUMPAD },
    [SC_NUMPAD_PLUS]    = { '+', NUMPAD },
    [SC_NUMPAD_1]       = { '1', NUMPAD },
    [SC_NUMPAD_2]       = { '2', NUMPAD },
    [SC_NUMPAD_3]       = { '3', NUMPAD },
    [SC_NUMPAD_0]       = { '0', NUMPAD },
    [SC_NUMPAD_DOT]     = { '.', NUMPAD },

    [SC_EXTENDED]       = { NO_DISPLAY, MULTIKEY }, // https://wiki.osdev.org/PS/2_Keyboard#Scan_Code_Set_1
    // prev track, next track, num enter, r ctrl, play, stop, num '/', r alt, arrow keys, pgup, pgdn, home, ins, dlt, prtsc
};

#endif

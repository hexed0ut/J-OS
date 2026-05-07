#ifndef KEYMAP_H
#define KEYMAP_H

#define NO_DISPLAY 0

enum KeyType
{
    NOT_IMPLEMENTED = 0,
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
    unsigned char ascii;
    enum KeyType type;
};

struct KeyMapValue keycode_ascii[256] = {
    [KEY_1_PRESSED]              = { '1', PRINTABLE }, [KEY_2_PRESSED]              = { '2', PRINTABLE }, [KEY_3_PRESSED]              = { '3', PRINTABLE },
    [KEY_4_PRESSED]              = { '4', PRINTABLE }, [KEY_5_PRESSED]              = { '5', PRINTABLE }, [KEY_6_PRESSED]              = { '6', PRINTABLE },
    [KEY_7_PRESSED]              = { '7', PRINTABLE }, [KEY_8_PRESSED]              = { '8', PRINTABLE }, [KEY_9_PRESSED]              = { '9', PRINTABLE },
    [KEY_0_PRESSED]              = { '0', PRINTABLE }, [KEY_MINUS_PRESSED]          = { '-', PRINTABLE }, [KEY_EQUALS_PRESSED]          = { '=', PRINTABLE },

    [KEY_Q_PRESSED]              = { 'q', PRINTABLE }, [KEY_W_PRESSED]              = { 'w', PRINTABLE }, [KEY_E_PRESSED]              = { 'e', PRINTABLE },
    [KEY_R_PRESSED]              = { 'r', PRINTABLE }, [KEY_T_PRESSED]              = { 't', PRINTABLE }, [KEY_Y_PRESSED]              = { 'y', PRINTABLE },
    [KEY_U_PRESSED]              = { 'u', PRINTABLE }, [KEY_I_PRESSED]              = { 'i', PRINTABLE }, [KEY_O_PRESSED]              = { 'o', PRINTABLE },
    [KEY_P_PRESSED]              = { 'p', PRINTABLE }, [KEY_LBRACKET_PRESSED]       = { '[', PRINTABLE }, [KEY_RBRACKET_PRESSED]       = { ']', PRINTABLE },

    [KEY_A_PRESSED]              = { 'a', PRINTABLE }, [KEY_S_PRESSED]              = { 's', PRINTABLE }, [KEY_D_PRESSED]              = { 'd', PRINTABLE },
    [KEY_F_PRESSED]              = { 'f', PRINTABLE }, [KEY_G_PRESSED]              = { 'g', PRINTABLE }, [KEY_H_PRESSED]              = { 'h', PRINTABLE },
    [KEY_J_PRESSED]              = { 'j', PRINTABLE }, [KEY_K_PRESSED]              = { 'k', PRINTABLE }, [KEY_L_PRESSED]              = { 'l', PRINTABLE },
    [KEY_SEMICOLON_PRESSED]      = { ';', PRINTABLE }, [KEY_APOSTROPHE_PRESSED]     = {'\'', PRINTABLE }, [KEY_GRAVE_PRESSED]          = { '`', PRINTABLE },

    [KEY_Z_PRESSED]              = { 'z', PRINTABLE }, [KEY_X_PRESSED]              = { 'x', PRINTABLE }, [KEY_C_PRESSED]              = { 'c', PRINTABLE },
    [KEY_V_PRESSED]              = { 'v', PRINTABLE }, [KEY_B_PRESSED]              = { 'b', PRINTABLE }, [KEY_N_PRESSED]              = { 'n', PRINTABLE },
    [KEY_M_PRESSED]              = { 'm', PRINTABLE }, [KEY_SPACE_PRESSED]          = { ' ', PRINTABLE },

    [KEY_BACKSLASH_PRESSED]      = { '\\', PRINTABLE },
    [KEY_COMMA_PRESSED]          = { ',',  PRINTABLE },
    [KEY_DOT_PRESSED]            = { '.',  PRINTABLE },
    [KEY_SLASH_PRESSED]          = { '/',  PRINTABLE },

    [KEY_LALT_PRESSED]     = { NO_DISPLAY, MODIFIER },
    [KEY_LSHIFT_PRESSED]   = { NO_DISPLAY, MODIFIER },
    [KEY_LSHIFT_RELEASED] = { NO_DISPLAY, MODIFIER },
    [KEY_RSHIFT_PRESSED]   = { NO_DISPLAY, MODIFIER },
    [KEY_RSHIFT_RELEASED] = { NO_DISPLAY, MODIFIER },
    [KEY_LCTRL_PRESSED]    = { NO_DISPLAY, MODIFIER },

    [KEY_NUMLOCK_PRESSED]        = { NO_DISPLAY, LOCK },
    [KEY_CAPSLOCK_PRESSED]       = { NO_DISPLAY, LOCK },
    [KEY_SCROLLLOCK_PRESSED]     = { NO_DISPLAY, LOCK },

    [KEY_ESCAPE_PRESSED]            = { NO_DISPLAY, SPECIAL },
    [KEY_TAB_PRESSED]            = { NO_DISPLAY, SPECIAL },
    [KEY_ENTER_PRESSED]          = { NO_DISPLAY, SPECIAL },
    [KEY_BACKSPACE_PRESSED]      = { NO_DISPLAY, SPECIAL },

    [KEY_F1_PRESSED]             = { NO_DISPLAY, FUNCTION },
    [KEY_F2_PRESSED]             = { NO_DISPLAY, FUNCTION },
    [KEY_F3_PRESSED]             = { NO_DISPLAY, FUNCTION },
    [KEY_F4_PRESSED]             = { NO_DISPLAY, FUNCTION },
    [KEY_F5_PRESSED]             = { NO_DISPLAY, FUNCTION },
    [KEY_F6_PRESSED]             = { NO_DISPLAY, FUNCTION },
    [KEY_F7_PRESSED]             = { NO_DISPLAY, FUNCTION },
    [KEY_F8_PRESSED]             = { NO_DISPLAY, FUNCTION },
    [KEY_F9_PRESSED]             = { NO_DISPLAY, FUNCTION },
    [KEY_F10_PRESSED]            = { NO_DISPLAY, FUNCTION },
    [KEY_F11_PRESSED]            = { NO_DISPLAY, FUNCTION },
    [KEY_F12_PRESSED]            = { NO_DISPLAY, FUNCTION },

    [KEY_NP_STAR_PRESSED]    = { '*', NUMPAD },
    [KEY_NP_7_PRESSED]       = { '7', NUMPAD },
    [KEY_NP_8_PRESSED]       = { '8', NUMPAD },
    [KEY_NP_9_PRESSED]       = { '9', NUMPAD },
    [KEY_NP_MINUS_PRESSED]   = { '-', NUMPAD },
    [KEY_NP_4_PRESSED]       = { '4', NUMPAD },
    [KEY_NP_5_PRESSED]       = { '5', NUMPAD },
    [KEY_NP_6_PRESSED]       = { '6', NUMPAD },
    [KEY_NP_PLUS_PRESSED]    = { '+', NUMPAD },
    [KEY_NP_1_PRESSED]       = { '1', NUMPAD },
    [KEY_NP_2_PRESSED]       = { '2', NUMPAD },
    [KEY_NP_3_PRESSED]       = { '3', NUMPAD },
    [KEY_NP_0_PRESSED]       = { '0', NUMPAD },
    [KEY_NP_DOT_PRESSED]     = { '.', NUMPAD },
};

char shift_map[128] = {
    ['1'] = '!',  ['2'] = '@',  ['3'] = '#',  ['4'] = '$',  ['5'] = '%',
    ['6'] = '^',  ['7'] = '&',  ['8'] = '*',  ['9'] = '(',  ['0'] = ')',

    ['-'] = '_',  ['='] = '+',  ['['] = '{',  [']'] = '}',  [' '] = ' ',
    [';'] = ':',  [','] = '<',  ['.'] = '>',  ['/'] = '?',  ['`'] = '~',
    ['\''] = '"', ['\\'] = '|',
};

#endif

#ifndef KEYMAP_H
#define KEYMAP_H

enum KeyType {
    PRINTABLE,
    MODIFIER,
    LOCK,
    SPECIAL,
    FUNCTION,
    NUMPAD,
    MULTIKEY
};

struct KeyMap {
    char scan_code;
    char key;
    enum KeyType type;
};

struct KeyMap ps2_us_qwerty[] = {
    {0x02,  '1', PRINTABLE}, {0x03, '2', PRINTABLE}, {0x04,  '3', PRINTABLE}, {0x05, '4', PRINTABLE},
    {0x06,  '5', PRINTABLE}, {0x07, '6', PRINTABLE}, {0x08,  '7', PRINTABLE}, {0x09, '8', PRINTABLE},
    {0x0A,  '9', PRINTABLE}, {0x0B, '0', PRINTABLE}, {0x0C,  '-', PRINTABLE}, {0x0D, '=', PRINTABLE},
    {0x10,  'q', PRINTABLE}, {0x11, 'w', PRINTABLE}, {0x12,  'e', PRINTABLE}, {0x13, 'r', PRINTABLE},
    {0x14,  't', PRINTABLE}, {0x15, 'y', PRINTABLE}, {0x16,  'u', PRINTABLE}, {0x17, 'i', PRINTABLE},
    {0x18,  'o', PRINTABLE}, {0x19, 'p', PRINTABLE}, {0x1A,  '[', PRINTABLE}, {0x1B, ']', PRINTABLE},
    {0x1E,  'a', PRINTABLE}, {0x1F, 's', PRINTABLE}, {0x20,  'd', PRINTABLE}, {0x21, 'f', PRINTABLE},
    {0x22,  'g', PRINTABLE}, {0x23, 'h', PRINTABLE}, {0x24,  'j', PRINTABLE}, {0x25, 'k', PRINTABLE},
    {0x26,  'l', PRINTABLE}, {0x27, ';', PRINTABLE}, {0x28, '\'', PRINTABLE}, {0x29, '`', PRINTABLE}, 
    {0x2B, '\\', PRINTABLE}, {0x33, ',', PRINTABLE}, {0x34,  '.', PRINTABLE}, {0x35, '/', PRINTABLE},
    {0x2C,  'z', PRINTABLE}, {0x2D, 'x', PRINTABLE}, {0x2E,  'c', PRINTABLE}, {0x2F, 'v', PRINTABLE},
    {0x30,  'b', PRINTABLE}, {0x31, 'n', PRINTABLE}, {0x32,  'm', PRINTABLE}, {0x39, ' ', PRINTABLE},
    
    {0x38, '\0', MODIFIER},    // left alt
    {0x2A, '\0', MODIFIER},    // left shift
    {0x36, '\0', MODIFIER},    // right shift
    {0x1D, '\0', MODIFIER},    // left control

    {0x45, '\0', LOCK},    // numlock
    {0x3A, '\0', LOCK},    // capslock
    {0x46, '\0', LOCK},    // scroll-lock

    {0x01, '\0', SPECIAL},    // ESC
    {0x0F, '\0', SPECIAL},    // tab
    {0x1C, '\0', SPECIAL},    // enter
    {0x0E, '\0', SPECIAL},    // backspace

    {0x3B, '\0', FUNCTION},    // F1
    {0x3C, '\0', FUNCTION},    // F2
    {0x3D, '\0', FUNCTION},    // F3
    {0x3E, '\0', FUNCTION},    // F4
    {0x3F, '\0', FUNCTION},    // F5
    {0x40, '\0', FUNCTION},    // F6
    {0x41, '\0', FUNCTION},    // F7
    {0x42, '\0', FUNCTION},    // F8
    {0x43, '\0', FUNCTION},    // F9
    {0x44, '\0', FUNCTION},    // F10
    {0x57, '\0', FUNCTION},    // F11
    {0x58, '\0', FUNCTION},    // F12

    {0x37, '*', NUMPAD},    // numpad '*'
    {0x47, '7', NUMPAD},    // numpad '7'
    {0x48, '8', NUMPAD},    // numpad '8'
    {0x49, '9', NUMPAD},    // numpad '9'
    {0x4A, '-', NUMPAD},    // numpad '-'
    {0x4B, '4', NUMPAD},    // numpad '4'
    {0x4C, '5', NUMPAD},    // numpad '5'
    {0x4D, '6', NUMPAD},    // numpad '6'
    {0x4E, '+', NUMPAD},    // numpad '+'
    {0x4F, '1', NUMPAD},    // numpad '1'
    {0x50, '2', NUMPAD},    // numpad '2'
    {0x51, '3', NUMPAD},    // numpad '3'
    {0x52, '0', NUMPAD},    // numpad '0'
    {0x53, '.', NUMPAD},    // numpad '.'

    {0xE0, '\0', MULTIKEY}    // https://wiki.osdev.org/PS/2_Keyboard#Scan_Code_Set_1
    // prev track, next track, num enter, r ctrl, play, stop, num '/', r alt, arrow keys, pgup, pgdn, home, ins, dlt, prtsc
};

#endif

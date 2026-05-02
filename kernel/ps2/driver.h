#ifndef DRIVER_H
#define DRIVER_H

#include "keymap.h"
#include "state.c"

unsigned char is_keypress() {
    return (inb(0x64) & 1);
}

char resolve_ps2_key(unsigned char inp) {
    int length = sizeof(ps2_us_qwerty) / sizeof(ps2_us_qwerty[0]);
    
    for (int i = 0; i < length; i++) {
        if (inp == ps2_us_qwerty[i].scan_code) {

            if (ps2_us_qwerty[i].type == PRINTABLE) {
                if (SHIFT_ACTIVE) {
                    return ps2_us_qwerty[i].key - 32;
                }
                else {
                    return ps2_us_qwerty[i].key;
                }
            }

            else if (ps2_us_qwerty[i].type == MODIFIER) {
                if (inp == 0x2A || inp == 0x36) {
                    SHIFT_ACTIVE = 1;
                }
                else if (inp == 0xAA || inp == 0xB6) {
                    SHIFT_ACTIVE = 0;
                }
            }
        }
    }
    return 0;
}

char await_ps2_key() {
    while (1) {
        if (is_keypress()) {
            unsigned char inp = inb(0x60); 
            return resolve_ps2_key(inp);
        }
    }
}

#endif
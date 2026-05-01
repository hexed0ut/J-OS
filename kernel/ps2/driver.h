#ifndef DRIVER_H
#define DRIVER_H

#include "keymap.h"
char await_ps2_key();

char is_keypress() {
    return (inb(0x64) & 1);
}


char resolve_ps2_key(char inp) {
    int length = sizeof(ps2_us_qwerty) / sizeof(ps2_us_qwerty[0]);
    for (int i = 0; i < length; i++) {
        if (inp == ps2_us_qwerty[i].scan_code) {

            if (ps2_us_qwerty[i].type == PRINTABLE) {
                return ps2_us_qwerty[i].key;
            }

            else if (ps2_us_qwerty[i].type == MODIFIER) {
                if (inp == 0x2A) {
                    char next = await_ps2_key();
                    return next-32;
                }
            }
        }
    }
    return 0;
}

char await_ps2_key() {
    while (1) {
        if (is_keypress()) {
            char inp = inb(0x60);
            if (resolve_ps2_key(inp) != 0) {
                return resolve_ps2_key(inp);
            }
        }
    }
}

#endif
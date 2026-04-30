#include "keymap.c"

char is_keypress() {
    return (inb(0x64) & 1);
}


char resolve_ps2_key(char inp) {
    int length = sizeof(ps2_us_qwerty)/sizeof(ps2_us_qwerty[0]);
    for (int i=0; i<length; i++) {
        if (inp == ps2_us_qwerty[i].scan_code) {
            return ps2_us_qwerty[i].key;
        }
    }
    return '\0';
}
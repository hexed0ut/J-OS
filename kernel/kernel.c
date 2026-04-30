#include "asm_utils/asm_utils.c"
#include "vga/console.c"
#include "vga/cursor.c"
#include "ps2/driver.c"

void kernel_main() {
    clear_vga_buffer();

    char* vga = 0xB8000;
    reset_cursor();

    int pos = 0;
    for (int i=1; i>0; i++) {
        if (is_keypress()) {
            char inp = inb(0x60);
            if (resolve_ps2_key(inp) != 0) {
                *(vga+pos) = resolve_ps2_key(inp);
                pos = pos+2;
                shift_cursor(1);
            }
        }
    }
}


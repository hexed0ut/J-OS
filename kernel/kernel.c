#include "asm_utils/asm_utils.h"
#include "vga/console.h"
#include "vga/cursor.h"
#include "ps2/driver.h"

void kernel_main() {
    clear_screen();
    stream_ps2_to_console();
}

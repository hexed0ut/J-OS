#include "asm_utils/asm_utils.c"
#include "vga/console.c"
#include "vga/cursor.c"
#include "ps2/keymap.c"

void clear_vga_buffer(void);
char is_keypress();
void move_cursor(int, int);

void kernel_main() {

    clear_vga_buffer();

    char* vga = 0xB8000;

    move_cursor(0,0);
    outb(0x3D4, 0x0A);
    outb(0x3D5, 0b00000000); //0 b 0000 1111
    int pos = 0;
    for (int i=1; i>0; i++){
        if (is_keypress()){
            char inp = inb(0x60);
            if (map(inp) != 0){
                *(vga+pos) = map(inp);
                pos = pos+2;
            }
        }
    }
}



char is_keypress(){
    return (inb(0x64) & 1);
}



// void k_print() {
//   char* vga = 0xB8000
//   *(vga) = 'T'
//   // char* crt_reg = 0x3D4
//   // k_print (*crt_reg)
// }

// int printb()

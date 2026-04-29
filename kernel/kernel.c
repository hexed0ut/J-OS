#include "asm_utils/asm_utils.c"
#include "ps2/keymap.c"

void clear_vga_buffer(void);
char is_keypress();
void move_cursor(int, int);

void kernel_main() {

  clear_vga_buffer();

  char* vga = 0xB8000;

  // *(vga) = 'T';
  // *(vga+1) = 0xAF;
  // *(vga+2) = 'E';

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

void clear_vga_buffer() {
  char* vga = 0xB8000;
  for (int i=0; i<80*25; i++) {
    *(vga+(i*2)) = 0;
    *(vga+(i*2)+1) = 0x07;
  }
}

char is_keypress(){
  return (inb(0x64) & 1);
}

// int is_keypress(int port)

void move_cursor(int row, int col){

  int pos = (row*80) + col;
  int hsb = pos/256;
  int lsb = pos%256;

  outb(0x3D4, 0x0E);
  outb(0x3D5, hsb);
  outb(0x3D4, 0x0F);
  outb(0x3D5, lsb);
}

// void k_print() {
//   char* vga = 0xB8000
//   *(vga) = 'T'
//   // char* crt_reg = 0x3D4
//   // k_print (*crt_reg)
// }

// int printb()

// void take_inp() {
//   get keystrokes
//   store keystrokes from 0xabcd to 0xabcd+no of keystrokes*2
//   char* msg = 0xabcd
//   k_print(msg)
// }
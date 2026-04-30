void clear_vga_buffer() {
    char* vga = 0xB8000;
    for (int i=0; i<80*25; i++) {
        *(vga+(i*2)) = 0;
        *(vga+(i*2)+1) = 0x07;
    }
}
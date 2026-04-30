void move_cursor(int row, int col){
    int pos = (row*80) + col;
    int hsb = pos/256;
    int lsb = pos%256;

    outb(0x3D4, 0x0E);
    outb(0x3D5, hsb);
    outb(0x3D4, 0x0F);
    outb(0x3D5, lsb);
}
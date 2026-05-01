#ifndef CURSOR_H
#define CURSOR_H

#include "../global.h"

void move_cursor(int row, int col) {
    int pos = (row*VGA_WIDTH) + col;
    int hsb = pos/256;
    int lsb = pos%256;

    outb(0x3D4, 0x0E);
    outb(0x3D5, hsb);
    outb(0x3D4, 0x0F);
    outb(0x3D5, lsb);
}

void reset_cursor() {
    move_cursor(0,0);
    outb(0x3D4, 0x0A);
    outb(0x3D5, 0b00000000);
}

void toggle_cursor_style() {
    outb(0x3D4, 0x0A);
    outb(0x3D5, (inb(0x3D5) ^ 0b00001110));
}

void toggle_cursor() {
    outb(0x3D4, 0x0A);
    outb(0x3D5, (inb(0x3D5) ^ 0b00100000));
}

int get_cursor_position() {
    outb(0x3D4, 0x0E);
    unsigned char hsb = inb(0x3D5);
    outb(0x3D4, 0x0F);
    unsigned char lsb = inb(0x3D5);
    return (hsb*256 + lsb);
}

void shift_cursor(int delta) {
    outb(0x3D4, 0x0F);
    unsigned char lsb = inb(0x3D5);
    if (lsb + delta < 256) {
        lsb += delta;
        outb(0x3D5, lsb);
    }
    else{
        outb(0x3D4, 0x0E);
        unsigned char hsb = inb(0x3D5);
        int pos = hsb*256 + lsb;
        pos += delta;
        hsb = pos/256;
        lsb = pos%256;
        outb(0x3D5, hsb);
        outb(0x3D4, 0x0F);
        outb(0x3D5, lsb);
    }
}

#endif
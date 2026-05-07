#ifndef ASM_UTILS_H
#define ASM_UTILS_H

void outb( int port, char value )
{
    asm volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
}

unsigned char inb( int port )
{
    unsigned char ret;
    asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

#endif
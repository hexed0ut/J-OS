#pragma once

// vga variables
#define VGA_BUFFER_START 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

// global keyboard modifier and lock states
int SHIFT_ACTIVE = 0;
int CAPSLOCK_ACTIVE = 0;
int NUMLOCK_ACTIVE = 0;
int CTRL_ACTIVE = 0;

// character insert mode
int OVERWRITE_ACTIVE = 0;
#include "vga/console.h"
#include "iostream.h"
#include "sh/shell.c"
#include "app/notepad.c"

void kernel_main()
{
    clear_screen();
    start_notepad();
	// start_shell();
}




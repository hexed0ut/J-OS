#pragma once

#include "commands.h"
#include "string.h"

void eval_shell_command( char* command )
{
	if ( strcmp( command, "hello" ) )
	{
		helloworld();
		return;
	}

	char error[2000];
	strcat( error, "<!> Command \"" );
	strcat( error, "\" not recognised\n" );

	std_output( error );
}
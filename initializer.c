#include "shell.h"

char **tokens;
char *current_cmdline;

void program_data_initializer()
{

	/* Initializes and allocated all memory needed by the shell */
	tokens = NULL;
	current_cmdline = NULL;
}

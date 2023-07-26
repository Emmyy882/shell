#include "shell.h"

/**
 * run_cmd - display the commandline prompt and gets input from the user
 * @prompt: thr commandline prompt
 * Rreturn: void
 */

/* keeps count of the number of executed command lines */
int exec_counter = 0;

void run_cmd(char *prompt)
{
	ssize_t bytes;
	int isbuiltin;
	int error_code;

	while (1)
	{
		exec_counter++;
		
		/* display prompt */
		write(STDIN_FILENO, prompt, strlen(prompt));

		/* get what is passed in command line */
		bytes = _getline();

		/* if command line is emppty */
		if (bytes == 0)
			continue;

		/* split command line arguments into tokens */
		tokenize();

		isbuiltin = error_code = built_in();
		if (isbuiltin == NOT_BUILTIN)
			error_code = execute_bin();

		if (error_code != EXIT_SUCCESS)
			print_error_message(); /* prints error message */

		free_ptr_array(tokens);
		free(current_cmdline);
	}
}

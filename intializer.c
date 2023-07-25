#include "shell.h"

char **tokens;
char *cur_cmdline;

void initialize_all_program_data() {

	/* Initializes and allocated all memory needed by the shell */
	tokens = NULL;
	cur_cmdline = NULL;
}

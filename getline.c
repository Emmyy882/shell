#include "shell.h"

ssize_t _getline()
{
	char cmdline[1024] = {'\0'};        /* Buffer to read the command line */
	static char *cmdlines[64] = {NULL}; /* Stores the commandlines */
	ssize_t len;
	char *line;
	int i = 0;
	
	/* Check if there is no pending command line to execute. */
	if (cmdlines[0] == NULL)
	{
		/* No pending command, so we need to read */
		len = read(STDIN_FILENO, cmdline, 1024);
		
		/* Check if EOF was read */
		if (len == 0)
		{
			/* Free any necessary data and exit since this will only occur in
			 * non-interactive mode */
			exit(errno);
		}
		
		/* Get all command lines from the command */
		line = _strtok(cmdline, "\n");
		while (line)
		{
			cmdlines[i] = strdup(line);
			i++;
			line = _strtok(NULL, "\n");
		}
	}
	
	/* Pick the first commandline and set it as the current command line to execute */
	cur_cmdline = cmdlines[0];
	
	/* Shift the commands to make the next command line be at the first index*/
	i = 0;
	while (cmdlines[i] != NULL)
		cmdlines[i] = cmdlines[i + 1];
	
	/* Check if the current command line is not null and return the length */
	if (current_cmdline)
		return strlen(current_cmdline);
	
	return (0);
}

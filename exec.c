#include "shell.h"

int get_path(char *command)
{
	char *path = _getenv("PATH");
	char *value;
	char *fullpath;
	
	strtok(path, "=");
	value = strtok(NULL, "=");
	value = strtok(value, ":");

	while (value)
	{
		fullpath = malloc((strlen(command) + 2 + strlen(value)) * sizeof(char));
		
	}

}


int execute(char **tokens)
{
	char *command = tokens[0];

	if (*command == '/' || *command == '.')
	{

	}

}

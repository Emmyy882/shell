#include "shell.h"

char **_strtok(char *str)
{
	char *token;
	char **tokens;
	index = 0;

	if (str[index] == '\0')
		return (NULL);

	tokens = malloc(sizeof(char) * 32);
	if (tokens == NULL)
	{
		perror("error in memory allocation");
		exit(1);
	}

	token = strtok(str, " ");
	while (token)
	{
		token = strdup(token);
		tokens[index] = token;
		index++;
		token = strtok(NULL, " ");
	}

	return (tokens);
}

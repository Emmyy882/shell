#include "shell.h"

void tokenize()
{
	char *token;
	char **tokens;
	index = 0;

	if (str[index] == '\0')
		return (NULL);

	tokens = malloc(sizeof(char) * 32);
	if (tokens == NULL)
	{
		exit(1);
	}

	token = _strtok(cmdline, " ");
	while (token)
	{
		_tokens[index] = strdup(token);
		index++;
		token = _strtok(NULL, " ");
	}

	tokens = _tokens;
}

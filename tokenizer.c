#include "shell.h"

void tokenize()
{
	char *token;
	char **_tokens;
	int index = 0;

	_tokens = malloc(sizeof(char) * 32);
	if (!_tokens)
	{
		exit(1);
	}

	token = _strtok(current_cmdline, " ");
	while (token)
	{
		_tokens[index++] = strdup(token);
		token = _strtok(NULL, " ");
	}

	tokens = _tokens;
}

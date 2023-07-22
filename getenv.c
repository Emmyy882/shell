#include "shell.h"

char *_getenv(char *key)
{
	int i;

	for (i = 0; envron[i]; i++)
	{
		if (strncmp(environ[i], key, strlen(key)) == 0)
		{
			write(STDOUT_FILENO, environ[i], 4


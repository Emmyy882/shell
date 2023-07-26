#include "shell.h"

char *_getenv(char *key)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], key, strlen(key)) == 0)
		{
			return (environ[i]);
		}
	}
	return (NULL);
}

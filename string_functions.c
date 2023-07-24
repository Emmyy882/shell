include "shell.h"

/**
 * _strcpy - copy a string
 * @dest: destination string
 * @src: the source string
 *
 * Return: copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	if (src == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;	
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char *_strtok(char *str, char *delim)
{
	static char *s; /* Local buffer to track the progress */
	int i;          /* Delimiter index */
	char *token;

	/* Set the buffer if we are calling the function the first time */
	if (str != NULL)
		s = str;
	
	/* Get the start of the token */
	for (; *s != '\0'; s++)
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*s == delim[i])
				break;
		}
		if (delim[i] == '\0')
			break;
	}
	
	/* Set the token to point to the start */
	token = s;
	if (*token == '\0')
		return (NULL);
	
	/* Set the end of the token */
	for (; *s != '\0'; s++)
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*s == delim[i])
			{
				*s = '\0';
				s++;
				return (token);
			}
		}
	}
	return (token);
}

#include "shell.h"

/**
 * main - begins execution of program
 * @ac: arugument counter
 * @av: array of  arguments
 * @envp: gets environment variable
 *
 * Return: Always successful
 */
int main(int ac, char *av[], char *envp[])
{
	char *readline = NULL;
	char *prompt = "";
	char *tokens;
	size_t n = 1024;
	size_t bytes;

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		prompt = "$ ";

	while (1)
	{
		/* display prompt */
		write(STDIN_FILENO, prompt, 2);

		readline = malloc(sizeof(char) * n);
		/* getting the input from the keyboard */
		bytes = getline(&readline, &n, stdin);
		if (bytes == -1)
		{
			free(readline);
			exit(EXIT_FAILURE);
		}

		if (readline[0]  != '\n')
		{
			tokens = _strtok(readline, " ");
			if (strcmp("exit", tokens) == 0)
				break;
		}
	}

}

#include "shell.h"

pid_t _getpid()
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Child process creation failed");
		free(child_pid);
	}
	else if (child_pid == 0)
	{
	}

}


/**
 * prompt - prompt for user input
 * @ac: arguement counter
 * @av: array that store passed arguments
 *
 * Return: nothing
 */
void prompt_user(int ac, char **av)
{
	int i;
	char *str = NULL;
	size_t n = 0;
	ssize_t strlen;
	
	while (1)
	{
		printf("#cisfun$ ");

		strlen = getline(&str, &n, stdin);
		if (strlen == -1)
		{
			free(lineptr);
			exit(EXIT_FAILURE);
		}

		i = 0;
		 while (str[i])
		{
			if (str[i] == '\n')
				str[i] = '\0';
		}

		 _getpid();
	}
}

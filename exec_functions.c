#include "shell.h"

int *get_path(char *command)
{
	char *path = strdup(_getenv("PATH"));
	char *value;
	char *fullpath;
	char *dir;
	int len;
	
	_strtok(path, "=");
	value = _strtok(NULL, "=");
	dir = _strtok(value, ":");

	while (dir != NULL)
	{
		/* get the length of fullpath */
		len = (strlen(command) + strlen(dir) + 2);
		
		/* allocate adequate memory for fullpath */
		fullpath = malloc(sizeof(char) * len);
		if (fullpath == NULL)
			exit(EXIT_FAILURE);

		/* generating the full path */
		_strcpy(fullpath, dir);
		_strcat(fullpath, "/");
		_strcat(fullpath, command);

		/* check if fullpath exist */
		if (access(fullpath, F_OK) == 0)
		{
			free(path);
			return (fullpath);
		}

		free(fullpath);
		dir = _strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}

void execute()
{
	pid_t pid;
	int status;

	pid = fork(); /* creating process */

	/* if process creation was not successful */
	if (pid == -1)
		exit(errno);

	/* if in child process execute command arguments */ 
	if (pid == 0)
	{
		execve(tokens[0], tokens, environ);
		exit(1);
	}
	if (pid > 0)
	{
		/* wait for child process to finish executing */
		waitpid(pid, &status, WUNTRACED);

		/* if the child process exited normally, set the errno to the exit code */
		if (WIFEXITED(status))
			errno = WIFEXITED(status);
	}
}

int execute_bin()
{
	char *command = tokens[0];
	char *path;

	if (command[0] == '/' || command[0] == '.')
	{
		if (access(command, F_OK) != 0 || access(command, X_Ok) != 0)
		{
			errno = 127;
			return (-1);
		}
	}
	else
	{
		path = get_path(command);

		if (path == NULL)
		{
			errno = 127;
			return (-1);
		}
		free(tokens[0]);
		tokens[0] = path;
	}

	/* execute the command */
	execute();
	return (0);
}

#include "shell.h"

/**
 * forkex - creates and executes child process
 * @str: string array
 * @envp: envrionment 
 *
 * Return: nothing
 */
void forkex(char **str, char *envp[])
{
	pid_t child_pid;
	int wstatus;

	child_pid = fork;
	if (child_pid == -1)
	{
		perror("Error: child process creation failed");
		return;
	}
	if (child_pid == 1)
	{
		if (exe


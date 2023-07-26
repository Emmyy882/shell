#include "shell.h"

/**
 * main - begins execution of program
 * @ac: arugument counter
 * @av: array of  arguments
 *
 * Return: Always successful
 */
char *command_name;
int main(int ac, char *av[])
{
	char *prompt = "";
	command_name = av[0];
	(void) ac;

	program_data_initializer();
	 /* check if shell is in interactive mode */
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		prompt = "$ ";
	
	run_cmd(prompt);
	return (0);
}

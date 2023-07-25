#include "shell.h"

/**
 * main - begins execution of program
 * @ac: arugument counter
 * @av: array of  arguments
 *
 * Return: Always successful
 */

char *cmd_name;

int main(int ac, char *av[])
{
	char *prompt = "";

	cmd_name = av[0];
	program_data_initializer();

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		prompt = "$ ";

	run_cmd(prompt);
	return (0);
}

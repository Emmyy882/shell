#include "shell.h"

char *num_to_str(int num)
{
	char *str;
	char *dup;
	int i, len;

	str = malloc(6 * sizeof(char));
	if (!str)
	exit(1);

	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	for (i = 0; num; i++)
	{
		str[i] = '0' + (num % 10);
		num /= 10;
	}
	str[i] = '\0';

	/* Reverse the string */
	dup = strdup(str);
	len = strlen(str);
	for (i = 0; --len >= 0; ++i)
	str[i] = dup[len];
	free(dup);
	return (str);
}

void print_error(char *msg) { write(STDERR_FILENO, msg, strlen(msg)); }

void print_error_message(void)
{
	char *err_no = num_to_str(execution_counter);

	print_error(program_name);
	print_error(": ");
	print_error(err_no);
	print_error(": ");
	print_error(tokens[0]);
	print_error(": ");

	if (errno == 126 || errno == 127)
	print_error(errno == 127 ? "not found\n" : "Permission denied\n");

	/* Print error specific to the cd command */
	if (strcmp(tokens[0], "cd") == 0)
	{
		print_error("can't cd to ");
		print_error(tokens[1]);
		print_error("\n");
	}

	free(err_no);
}

#include <unistd.h>
#include <stdio.h>

/**
 * main - runs program
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("%u\n", my_pid);
	return (0);
}

#include <unistd.h>
#include <stdio.h>

//extern char **environ;

int main(int argc, char **argv )
{
	int i = 0;

	while (argv[i] != NULL)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	
	return (0);
}

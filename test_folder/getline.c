#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//FILE *fd;
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t command_length; 

	while (1)
	{
		printf("$ ");

		command_length = getline(&command, &bufsize, stdin);

		//if error or EOF, break out of the loop
		if (command_length == -1)
			break;

		//removing the newline character
		command[command_length -1] = '\0';

		//if user entered exit, break out of the loop
		if (strcmp(command, "exit") == 0)
			break;

		printf("%s\n", command);
	}
	free(command);

	
	return (0);
}

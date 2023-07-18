#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int i = 0;
	char *go[] = {"mike", "peter", "school"};

	while (go[i])
	{
		printf("%s ", go[i]);
		i++;
	}
}

#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

char **_strtok(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

#endif

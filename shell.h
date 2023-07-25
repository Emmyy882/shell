#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

#define NOT_BUILTIN 67

extern int errno;
extern char **environ;
extern int exec_counter;
extern char **tokens;
extern char *current_cmdline;
extern char *command_name;

typedef struct builtin {
	char *name;
	int (*action)();
} builtin_action;

char **_strtok(char *str, char *delim);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void run_cmd(char *prompt);
void tokenize();
int execute_bin();
void program_data_initializer();
char *_getenv(char *key);
int is_builtin();
ssize_t _getline();
void free_ptr_array(char **arr);
void print_error_message();

#endif

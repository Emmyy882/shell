#include "shell.h"

int builtin_exit() {
  int status = 0;

  if (tokens[1] != NULL)
    status = atoi(tokens[1]);

  /* Free any necessary program data */
  free_pointers_array(tokens);
  free(cur_cmdline);
  exit(status);
}

int builtin_env() {
  int i;

  (void)tokens;

  for (i = 0; environ[i]; i++) {
    write(STDOUT_FILENO, environ[i], strlen(environ[i]));
    write(STDOUT_FILENO, "\n", 1);
  }
  return (0);
}

int builtin_cd() {
  char dir[1024] = {'\0'};

  if (tokens[1] == NULL) {
    /* Normally you have to cd to the $HOME directory. But this is not required
     * yet from task 1 to 10 */
    errno = 127;
    return (-1);
  }

  if (chdir(tokens[1]) == -1) {
    /* If we aren't able to cd to the directory return -1 for unsuccessful
     * execution */
    return (-1);
  }

  /* Get the current working directory */
  getcwd(dir, 1024);
  /* Set the PWD to dir */
  setenv("PWD", dir, 0);
  return (0);
}

int is_builtin() {

  builtin_action actions[] = {{"exit", builtin_exit},
                              {"env", builtin_env},
                              {"cd", builtin_cd},

                              {NULL, NULL}};
  int i;

  for (i = 0; actions[i].name; i++) {
    /* Compare the commmand with the inbuilt commands to find a match */
    if (strcmp(actions[i].name, tokens[0]) == 0) {
      return (actions[i].action());
    }
  }

  /* No match was found */
  return (NOT_BUILTIN);
}

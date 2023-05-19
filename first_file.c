#include "shs.h"
#include <sys/wait.h>

#define MAX_COMMAND 10
/**
* first_file – execute terminal commad.
*
* @agv: argument vector.
* @env: environment vector.
*
* Return: execution.
*/
void first_file(char **argv, char **env)
{
char *line = NULL;
size_t len = 0;
ssize_t read;
char **args = parse_args(line); // Extracts and tokenizes command line arguments

while (1) {
printf("cisfun$ ");

read = getline(&line, &len, stdin);
if (read == -1) {
free(line);
exit(EXIT_FAILURE);
}

if (args[0] == NULL) { // Skips if no command is entered
free(args);
continue;
}

if (is_builtin(args)) { // Executes built-in commands
execute_builtin(args);
} else { // Executes external commands
execute_external(args, env);
}

free(args);
}
}


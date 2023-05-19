#include "shs.h"
#include <sys/wait.h>

#define MAX_COMMAND 10
/**
 * first_file - Executes terminal commands
 *
 * @argv: Argument vector
 * @env: Environment vector
 */
void first_file(char **argv, char **env)
{
char *line = NULL;
size_t len = 0;
ssize_t read;
char **args;
while (1)
{
printf("cisfun$ ");
read = getline(&line, &len, stdin);
if (read == -1)
{
free(line);
exit(EXIT_FAILURE);
}
/*Extracts and tokenizes command line arguments*/
args = parse_args(line);
/*Skips if no command is entered*/
if (args[0] == NULL)
{
free(args);
continue;
}
/*Executes built-in commands*/
if (is_builtin(args))
{
execute_builtin(args);
}
else
{
/*Executes external commands*/
execute_external(args, env);
}
free(args);
}
}


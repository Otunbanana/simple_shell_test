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
void first_file(char **agv, char **env)
{
char *args[MAX_COMMAND];
int arg_count = 0;
char *command = NULL;
size_t n = 0;
ssize_t num_char;
pid_t pid;

while (1)
{
printf("cisfun$ ");

num_char = getline(&command, &n, stdin);
if (num_char == -1)
{
free(command);
exit(EXIT_FAILURE);
}

args[arg_count] = strtok(command, " ");
while (args[arg_count] != NULL && arg_count < MAX_COMMAND)
{
arg_count++;
args[arg_count] = strtok(NULL, " ");
}
args[arg_count] = NULL;

pid = fork();
if (pid == -1)
{
free(command);
exit(EXIT_FAILURE);
}

if (pid == 0)
{
execve(args[0], args, env);
printf("%s: No such file or directory\n", args[0]);
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}
}


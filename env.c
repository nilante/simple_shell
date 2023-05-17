#include "main.h"
void execute_command(char **args)
{
if (args[0] == NULL)
{
/**
*  Empty command
*/
return;
}
if (strcmp(args[0], "env") == 0) 
{
/* Handle the "env" built-in command */
env_builtin();
}
else
{
/* Handle external commands */
pid_t pid = fork();

if (pid == 0)
{
/* Child process */
if (execvp(args[0], args) == -1)
{
perror("execvp");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
/* Forking error */
perror("fork");
}
else
{
/* Parent process */
wait(NULL);
}
}
}

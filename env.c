#include "main.h"
/*
 * execute_com - a function Implement the env built-in, that prints the current environment
 * @args: the string
 * return: 0
 */
void execute_com(char **args)
{

if (args[0] == NULL)
{
return;
}
if (strcmp(args[0], "env") == 0)
{
/* Handle the "env" built-in command */
env_builtin();
    if (args[0] == NULL)
    {
        /* Empty command*/
        return;
    }

if (strcmp(args[0], "env") == 0)
{
        /* Handle the "env" built-in command*/
env_builtin();
}
else {
        /* Handle external commands*/
        pid_t pid = fork();

        if (pid == 0)
       	{
            /* Child process*/
            if (execvp(args[0], args) == -1) {
                perror("execvp");
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0)
       	{
            /* Forking error*/
            perror("fork");
        } else 
	{
            /* Parent process*/
            wait(NULL);
        }
    }

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

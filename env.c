#include "main.h"
void execute_com(char **args)
{
<<<<<<< HEAD
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
=======
    if (args[0] == NULL) {
        /* Empty command*/
        return;
    }

    if (strcmp(args[0], "env") == 0) {
        /* Handle the "env" built-in command*/
        env_builtin();
    } else {
        /* Handle external commands*/
        pid_t pid = fork();

        if (pid == 0) {
            /* Child process*/
            if (execvp(args[0], args) == -1) {
                perror("execvp");
            }
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            /* Forking error*/
            perror("fork");
        } else {
            /* Parent process*/
            wait(NULL);
        }
    }
>>>>>>> 1fd0ea836044b7b95e47968a2e24fb3ad82b2650
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

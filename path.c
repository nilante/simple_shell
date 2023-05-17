#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

<<<<<<< HEAD
char *search_path(char *com)
{
char *path = getenv("PATH");
char *x;
/*fp:full path */
char *fp;
char *token;

token = strtok(path, ":");
while (token != NULL)
{
x = strdup(token);
fp = malloc(strlen(dir) + strlen(command) + 2);
sprintf(full_path, "%s/%s", dir, command);

if (access(fp, F_OK) == 0)
{
free(x);
return fp;
}
free(x);
free(fp);
token = strtok(NULL, ":");
}
return (0)
=======
#define BUFFER_SIZE 1024

int main(void)
{
char com[BUFFER_SIZE];
char p[] = "simple_shell> ";

while (1) 
{
printf("%s", p);
if (fgets(com, sizeof(com), stdin) == NULL)
break;  // End of file (Ctrl+D) reached, exit the shell

// Remove the trailing newline character
com[strcspn(com, "\n")] = '\0';

char *args[BUFFER_SIZE];
int x = 0;

// Tokenize the command line into arguments
char *token = strtok(command, " ");
while (token != NULL) 
{
args[x++] = token;
token = strtok(NULL, " ");
}
args[x] = NULL;
pid_t pid = fork();
if (pid < 0)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0) 
{
/**
* Child process
* Execute the command with arguments
*/
execvp(args[0], args);

/**
*
* If execvp returns, it means the command doesn't exist
* return : 0 success
*/            
fprintf(stderr, "Command not found: %s\n", args[0]);
exit(EXIT_FAILURE);
}
else
{
/**
* Parent process
* return : 0 success
*/

int status;
waitpid(pid, &status, 0);

if (status != 0)
{
printf("Command execution failed\n");
}
}
}
printf("\n");  
/**
*  Print a new line before exiting the shell
*  return : 0 success
*/
return 0;
>>>>>>> 03f1979a937c88264df2b1ecfd54542db27ec6f2
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
/**
* pid : process ID
* fork : system call used for creating a new process in linux
*/
pid_t pid = fork();
if (pid < 0) {
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
/**
* Child process
* Execute the command
*/
if (execlp(com, com, (char *)NULL) == -1) {
perror("execlp");
exit(EXIT_FAILURE);
}
}
else
{
// Parent process
int status;
aitpid(pid, &status, 0);
if (status != 0) 
{
printf("Command execution failed\n");
}
}
}
printf("\n");  // Print a new line before exiting the shell
return 0;
}

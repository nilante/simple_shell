#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(void)
{
char com[BUFFER_SIZE];
char p[] = "simple_shell> ";
while (1) {
printf("%s", p);
if (fgets(com, sizeof(com), stdin) == NULL)
break;  // End of file (Ctrl+D) reached, exit the shell

// Remove the trailing newline character
com[strcspn(com, "\n")] = '\0';
char *args[BUFFER_SIZE];
int i = 0;
// Tokenize the command line into arguments
char *token = strtok(com, " ");
while (token != NULL) {
args[i++] = token;
token = strtok(NULL, " ");
}
args[i] = NULL;
pid_t pid = fork();
if (pid < 0) 
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0) {
// Child process
// Execute the command with arguments
if (execvp(args[0], args) == -1) {
perror("execvp");
exit(EXIT_FAILURE);
}
}
else {
// Parent process
int status;
waitpid(pid, &status, 0);
if (status != 0) {
printf("Command execution failed\n";
}
}
}
printf("\n");  // Print a new line before exiting the shell
return 0;
}

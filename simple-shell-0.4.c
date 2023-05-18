#include "main"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMMAND_SIZE 10
/**
 * exit_command - check the main function
 * Return: 0
 */
void exit_command(void)
{
printf("Exiting the shell.\n");
exit(0);
}
int main(void)
{
char com[COMMAND_SIZE];
while (1)
{
printf("$ ");
fgets(com, COMMAND_SIZE, stdin);
com[strcspn(com, "\n")] = '\0'; /* Remove trailing newline character */
if (strcmp(com, "exit") == 0)
{
exit_command();
}
else
{
printf("Executing: %s\n", com);
/* Execute other commands here */
}
}
return (0);
}

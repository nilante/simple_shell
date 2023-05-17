#include "main.h"
int main(void)
{
char *line;
char **args;

while (1)
{
printf("> ");
line = read_line();  /* Read a line of input from the user*/
args = split_line(line);  /* Split the line into arguments*/
execute_command(args);  /* Execute the command */
free(line);
free(args);
}

return (0);
}

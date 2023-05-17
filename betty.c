#include "main.h"
int main(void)
{
char *l;
char **ar;

while (1)
{
printf("> ");
line = read_line();  /* Read a line of input from the user */
ars = split_line(line);  /* Split the line into arguments */
execute_command(args);  /* Execute the command */
free(l);
free(ar);
}
return (0);
}

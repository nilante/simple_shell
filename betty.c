#include "main.h"
int main(void)
{
<<<<<<< HEAD
char *l;
char **ar;
=======
char *line;
char **args;
>>>>>>> 1fd0ea836044b7b95e47968a2e24fb3ad82b2650

while (1)
{
printf("> ");
<<<<<<< HEAD
line = read_line();  /* Read a line of input from the user */
ars = split_line(line);  /* Split the line into arguments */
execute_command(args);  /* Execute the command */
free(l);
free(ar);
}
=======
line = read_line();  /* Read a line of input from the user*/
args = split_line(line);  /* Split the line into arguments*/
execute_command(args);  /* Execute the command */
free(line);
free(args);
}

>>>>>>> 1fd0ea836044b7b95e47968a2e24fb3ad82b2650
return (0);
}

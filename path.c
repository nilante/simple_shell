#include "main.h"

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
}

#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *read_line(void);
char **split_line(char *line);
void execute_command(char **args);
char com[BUFFER_SIZE];
fprintf(stderr, "Command not found: %s\n", args[0]);
char com[BUFFER_SIZE];
#endif /* MAIN_H*/


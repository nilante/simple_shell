#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024;
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
char command(BUFFER_SIZE);
char *read_line(void);
char **split_line(char *line);
void execute_command(char **args);
fprintf(stderr, "Command not found: %s\n", args[0]);
#endif /* MAIN_H*/


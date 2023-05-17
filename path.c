#include "main.h"

char *search_path(char *command)
{
    char *path = getenv("PATH");
    char *dir;
    char *full_path;
    char *token;

    token = strtok(path, ":");

    while (token != NULL) {
        dir = strdup(token);
        full_path = malloc(strlen(dir) + strlen(command) + 2);
        sprintf(full_path, "%s/%s", dir, command);

        if (access(full_path, F_OK) == 0) {
            free(dir);
            return full_path;
        }

        free(dir);
        free(full_path);
        token = strtok(NULL, ":");
    }

    return

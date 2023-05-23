#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


void print_environment(char **env)
{
    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}

char *get_environment_variable(char **env, const char *name)
{
    while (*env)
    {
        if (strncmp(*env, name, strlen(name)) == 0 && (*env)[strlen(name)] == '=')
            return (*env) + strlen(name) + 1;

        env++;
    }
    return NULL;
}

int set_environment_variable(const char *name, const char *value)
{
    if (setenv(name, value, 1) != 0)
    {printf("Failed to set environment variable\n");
        return 1;
    }

    return 0;
}

int unset_environment_variable(const char *name)
{
    if (unsetenv(name) != 0)
    {
        printf("Failed to unset environment variable: %s\n", name);
        return 1;
    }

    return 0;
}

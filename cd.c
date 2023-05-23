/**
 * myShellExit - This function is responsible for terminating the shell program.
 * @data: a pointer to a structure containing the necessary information and
 * Return: Returns -2 to indicate the shell 
 * program should exit.
 * Returns 0 if data->args[0] != "exit".
 */
 typedef struct passdata
{
	char *args;
	char **argv;
} data_t;


int myShellExit(data_t *data)
{
    int exitStatus;

    if (data->args[1]) /* If there is an exit argument */
    {
        exitStatus = stringToInteger(data->args[1]);
        if (exitStatus == -1)
        {
            data->errorCode = 2;
            printErrorMessage(data, "Illegal number: ");
            printString(data->args[1]);
            printCharacter('\n');
            return 1;
        }
        data->errorCode = stringToInteger(data->args[1]);
        return -2;
    }
    data->errorCode = -1;
    return -2;
}
/**
 * changeDirectory - This function is responsible 
 * for changing the current directory
 * of the process. It takes a pointer to 
 * a structure 'data' containing the necessary
 * information and arguments.
 * @data: A pointer to a structure containing 
 * the necessary information and 
 * arguments for the function.
 * Return: Always returns 0.
 */
int changeDirectory(data_t *data)
{
    char **argArray;

    argArray = data->args;
    printString("changeDirectory function called. Function not yet implemented.\n");
    if (0)
        printString(*argArray); /* Temporary unused workaround */
    return 0;
}
**
 * changeCurrentDirectory - changes the current directory of the process
 * @data: Structure containing relevant information and arguments.
 *        Used to maintain a constant function prototype.
 * Return: Always returns 0
 */
int changeCurrentDirectory(data_t *data)
{
    char *s, *dir, buffer[1024];
    int chdir_ret;

    s = getcwd(buffer, 1024);
    if (!s)
        printString("TODO: >>getcwd failure emsg here<<\n");

    if (!data->args[1])
    {
        dir = _getenv(data, "HOME=");
        if (!dir)
            chdir_ret = /* TODO: what should this be? */ chdir((dir = _getenv(data, "PWD=")) ? dir : "/");
        else
            chdir_ret = chdir(dir);
    }
    else if (_strcmp(data->args[1], "-") == 0)
    {
        if (!_getenv(data, "OLDPWD="))
        {
            printString(s);
            printCharacter('\n');
            return 1;
        }
        printString(_getenv(data, "OLDPWD="));
        printCharacter('\n');
        chdir_ret = /* TODO: what should this be? */ chdir((dir = _getenv(data, "OLDPWD=")) ? dir : "/");
    }
    else
        chdir_ret = chdir(data->args[1]);

    if (chdir_ret == -1)
    {
        printErrorMessage(data, "can't cd to ");
        printString(data->args[1]);
        printCharacter('\n');
    }
    else
    {
        _setenv(data, "OLDPWD", _getenv(data, "PWD="));
        _setenv(data, "PWD", getcwd(buffer, 1024));
    }

    return 0;
}

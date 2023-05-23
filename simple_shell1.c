#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

/**
 * is_shell_interactive - checks if the shell is in interactive mode
 * Return: true if the shell is in interactive mode, false otherwise
 */
/**
*bool type is a data type that represents 
*a boolean value, which can have one 
* of two states: true or false. It is 
* commonly used to store logical values and
* make decisions based on their truthfulness
*/
bool is_shell_interactive(void)
{
    return isatty(fileno(stdin)) != 0;
}
/**
 * character_delimiter - checks if a character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int character_delimiter(char c, char *delim)
{
    while (*delim != '\0')
    {
        if (*delim == c)
            return 1;
              delim++;
    }
    return 0;
}
/**
 * This code defines a function called delimiter
 * that checks if a given character c is a delimiter
 * The function takes two parameters
 * /
 =====================================
 / **
 * check_alpha - checks for alphabetic character
 * @c: The character to check
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int check_alpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/**
*The code is checking for alphabetic characters.
*The character to input is c and the return
* value is 1 if c is an alphabetic character
* , 0 otherwise.
*/
/**
 * convert_string_to_integer - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int convert_string_to_integer(char *s)
{
    int sign = 1;
    unsigned int result = 0;

    while (*s)
    {
        if (*s >= '0' && *s <= '9')
        {
            result = result * 10 + (*s - '0');
        }
        else if (result != 0)
        {
            break;
        }
        s++;
    }

    return sign * result;
}
/**
 * The code takes a string and converts it 
 * to an integer
 */

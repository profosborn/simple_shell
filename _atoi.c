#include "shell.h"

/**
 * isInteractiveMode - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int isInteractiveMode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * isDelimiter- checks for delimiter character
 * @c: character to check
 * @delim: delimiter string
 * Return: 1 if true, 0 if false
 */
int isDelimiter(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * isAlphabetic- checks for alphabetic character
 * @c: character to check
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int isAlphabetic(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/**
 *stringToInteger-  checks to convert string to integer
 * @s: string to be converted
 * Return: 0 if no numbers are found in the string, converted number otherwise
 */

int stringToInteger(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

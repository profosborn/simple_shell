#include "shell.h"

/**
<<<<<<< HEAD
 * isInteractiveMode - returns true if shell is interactive mode
=======
 * interactive - returns true if shell is interactive mode
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
<<<<<<< HEAD
int isInteractiveMode(info_t *info)
=======
int interactive(info_t *info)
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
<<<<<<< HEAD
 * isDelimiter:  checks if a character is a delimiter
 * @c: character to check
 * @delim: delimiter string
 * Return: 1 if true, 0 if false
 */
int isDelimiter(char c, char *delim)
=======
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
<<<<<<< HEAD
 * isAlphabetic: checks if a character is alphabetic
 * @c: character to check
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int isAlphabetic(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
=======
 *_isalpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
		return (1);
	else
		return (0);
}

/**
<<<<<<< HEAD
 * stringToInteger: converts a string to an integer
 * @s: string to be converted
 * Return: 0 if no numbers are found in the string, converted number otherwise
 */

int stringToInteger(char *s)
=======
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

<<<<<<< HEAD
	for (i = 0; s[i] != '\0' && flag != 2; i++)
=======
	for (i = 0;  s[i] != '\0' && flag != 2; i++)
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
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

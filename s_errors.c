#include "shell.h"

/**
<<<<<<< HEAD
 * printErrorMessage - prints an error message
 * @message: the error message to be printed
 *
 * Return: Nothing
 */
void printErrorMessage(char *message)
{
	int i = 0;

	if (!message)
		return;
	while (message[i] != '\0')
	{
		writeToStderr(message[i]);
=======
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
		i++;
	}
}

/**
<<<<<<< HEAD
 * writeToStderr - writes the character c to stderr
=======
 * _eputchar - writes the character c to stderr
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
<<<<<<< HEAD
int writeToStderr(char c)
=======
int _eputchar(char c)
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
<<<<<<< HEAD
 * writeToFileDescriptor - writes the character c to the given file descriptor
 * @c: The character to print
 * @fd: The file descriptor to write to
=======
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
<<<<<<< HEAD
int writeToFileDescriptor(char c, int fd)
=======
int _putfd(char c, int fd)
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
<<<<<<< HEAD
 * printStringToFileDescriptor - prints an input string to
 * the given file descriptor
 * @
str: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of chars put
 */
int printStringToFileDescriptor(char *str, int fd)
{
	int count = 0;
=======
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98

	if (!str)
		return (0);
	while (*str)
	{
<<<<<<< HEAD
		count += writeToFileDescriptor(*str++, fd);
	}
	return (count);
=======
		i += _putfd(*str++, fd);
	}
	return (i);
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
}

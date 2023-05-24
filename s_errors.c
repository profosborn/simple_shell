#include "shell.h"

/**
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
		i++;
	}
}

/**
 * writeToStderr - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int writeToStderr(char c)
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
 * writeToFileDescriptor - writes the character c to the given file descriptor
 * @c: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int writeToFileDescriptor(char c, int fd)
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

	if (!str)
		return (0);
	while (*str)
	{
		count += writeToFileDescriptor(*str++, fd);
	}
	return (count);
}

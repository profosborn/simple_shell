#include "shell.h"

/**
<<<<<<< HEAD
 * displayHistory - displays the history list, one command by line, preceded
=======
 * _myhistory - displays the history list, one command by line, preceded
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
<<<<<<< HEAD
int displayHistory(info_t *info)
=======
int _myhistory(info_t *info)
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
{
	print_list(info->history);
	return (0);
}

/**
<<<<<<< HEAD
 * unsetAlias - unsets an alias by setting it to an empty string
=======
 * unset_alias - sets alias to string
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
<<<<<<< HEAD
int unsetAlias(info_t *info, char *str)
{
	char *equals, temp;
	int ret;

	equals = _strchr(str, '=');
	if (!equals)
		return (1);
	temp = *equals;
	*equals = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*equals = temp;
=======
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
	return (ret);
}

/**
<<<<<<< HEAD
 * setAlias - sets alias to a string
=======
 * set_alias - sets alias to string
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
<<<<<<< HEAD
int setAlias(info_t *info, char *str)
{
	char *equals;

	equals = _strchr(str, '=');
	if (!equals)
		return (1);
	if (!*++equals)
		return (unsetAlias(info, str));

	unsetAlias(info, str);
=======
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
<<<<<<< HEAD
 * printAlias - prints an alias string
=======
 * print_alias - prints an alias string
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
<<<<<<< HEAD
int printAlias(list_t *node)
{
	char *equals = NULL, *alias = NULL;

	if (node)
	{
		equals = _strchr(node->str, '=');
		for (alias = node->str; alias <= equals; alias++)
		_putchar(*alias);
		_putchar('\'');
		_puts(equals + 1);
=======
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
<<<<<<< HEAD
 * aliasCommand - mimics the alias builtin (man alias)
=======
 * _myalias - mimics the alias builtin (man alias)
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
<<<<<<< HEAD
int aliasCommand(info_t *info)
{
	int i = 0;
	char *equals = NULL;
=======
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
<<<<<<< HEAD
			printAlias(node);
=======
			print_alias(node);
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
<<<<<<< HEAD
		equals = _strchr(info->argv[i], '=');
		if (equals)
			setAlias(info, info->argv[i]);
		else
			printAlias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
=======
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
>>>>>>> 6639a309babcb0c0cd04de0a6720d92fa674cd98

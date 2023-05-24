#include "shell.h"

/**
 * displayHistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int displayHistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unsetAlias - unsets an alias by setting it to an empty string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
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
	return (ret);
}

/**
 * setAlias - sets alias to a string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int setAlias(info_t *info, char *str)
{
	char *equals;

	equals = _strchr(str, '=');
	if (!equals)
		return (1);
	if (!*++equals)
		return (unsetAlias(info, str));

	unsetAlias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * printAlias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
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
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * aliasCommand - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int aliasCommand(info_t *info)
{
	int i = 0;
	char *equals = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			printAlias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		equals = _strchr(info->argv[i], '=');
		if (equals)
			setAlias(info, info->argv[i]);
		else
			printAlias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);

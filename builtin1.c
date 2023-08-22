#include "shell.h"

/**
 * _show_historiq_list - displays the history list, one command by line
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _show_historiq_list(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * _sets_string - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int _sets_string(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strlocach(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * alias_string - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int alias_string(info_t *info, char *str)
{
	char *p;

	p = _strlocach(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (_sets_string(info, str));

	_sets_string(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * alias_string_print - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int alias_string_print(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strlocach(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _mimics_alias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _mimics_alias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			alias_string_print(node);
			node = node->next;
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		p = _strlocach(info->argv[i], '=');
		if (p)
			alias_string(info, info->argv[i]);
		else
			alias_string_print(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

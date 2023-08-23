#include "shell.h"

/**
 * _current_myenvironnment_alias - Prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _current_myenvironnment_alias(info_t *info)
{
	print_list(info->env);
	return (0);
}

/**
 * _gets_value_variable - Gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: Env var name
 * Return: The value
 */
char *_gets_value_variable(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}

	if (_setenv_var(info, info->argv[1], info->argv[2]))
		return (0);

	return (1);
}

/**
 * _myremovenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myremovenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}

	for (i = 1; i <= info->argc; i++)
		_unsetenv_remo_remo(info, info->argv[i]);

	return (0);
}

/**
 * populates_linked_list - Populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int populates_linked_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);

	info->env = node;
	return (0);
}


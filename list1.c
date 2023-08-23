#include "shell.h"
/**
 * list_len - determines length of linked list
 * @h: pointer to first node
 * Return: size of list
 */

size_t list_len(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		h = h->next;
		a++;
	}
	return (a);
}

/**
 * list_to - returns an array of strings of the list->str
 * @head: pointer to first node
 * Return: array of strings
 */

char **list_to(list_t *head)
{
	list_t *node = head;
	size_t a = list_len(head), b;
	char **strs;
	char *str;

	if (!head || !a)
		return (NULL);

	strs = malloc(sizeof(char *) * (a + 1));

	if (!strs)
		return (NULL);

	for (a = 0; node; node = node->next, a++)
	{
		str = malloc(_strlen(node->str) + 1);

		if (!str)
		{
			for (b = 0; b < a; b++)
				free(strs[b]);

			free(strs);
			return (NULL);
		}
		
		_strncpy(str, node->str, some_max_length);
		str[some_max_length] = '\0';
		strs[a] = str;
	}

	strs[a] = NULL;
	return (strs);
}

/**
 * print_lists - prints all elements of a list_t linked list
 * @h: pointer to first node
 * Return: size of list
 */

size_t print_lists(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		a++;
	}	
	return (a);
}

/**
 * node_starts - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 * Return: match node or nul
 */

list_t *node_starts(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);

		if (p && ((c == -1) || (*p == c)))
			return (node);

		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_inde - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 * Return: index of node or -1
 */

ssize_t get_node_inde(list_t *head, list_t *node)
{
	size_t a = 0;
	while (head)
	{
		if (head == node)
			return (a);

		head = head->next;
		a++;
	}

	return (-1);
}


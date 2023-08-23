#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 * Return: integer length of strina
 */

int _strlen(char *b)
{
	int a = 0;

	if (!b)
		return (0);

	while (*b++)
		a++;

	return (a);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @a: the first strang
 * @b: the second strang
 * Return: negative if a < b, positive if a > b, zero if a == b
 */

int _strcmp(char *a, char *b)
{
	while (*a && *b)
	{
		if (*a != *b)
			return (*a - *b);

		a++;
		b++;
	}

	if (*a == *b)
		return (0);

	else
		return (*a < *b ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @hays: string to search
 * @need: the substring to fin
 * Return: address of next char of hays or NULL
 */

char *starts_with(const char *hays, const char *need)
{
	while (*need)
		if (*need++ != *hays++)
			return (NULL);

	return ((char *)hays);
}


/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 * Return: pointer to destination buffe
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = *src;
	return (ret);

}


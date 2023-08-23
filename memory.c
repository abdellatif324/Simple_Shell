#include "shell.h"

/**
 * beffur_free - frees a pointer and NULLs the address
 * @ptr: address of the pointer to fre
 * Return: 1 if freed, otherwise 0.
 */

int beffur_free(void **ptr)
{	
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
        }
	return (0);
}


#include "monty.h"

/**
 * _strdup - returns a pointer to a duplicate of a string
 * @str: string
 * Return: pointer to duplicate string
 */

char *_strdup(char *str)
{
	int x, length;
	char *ptr;

	x = length = 0;
	if (str == NULL)
		return (NULL);
	length = strlen(str);
	ptr = (char *)malloc(sizeof(char) * length + 1);
	if (ptr == NULL)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}
	while (str[x])
	{
		ptr[x] = str[x];
		x++;
	}
	ptr[x] = '\0';
	return (ptr);
}

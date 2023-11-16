#include "monty.h"

/**
 * check_comment - checks its argument for a comment(preceded by a space)
 * and if found, removes the rest of the characters (comment inclusive)
 * @str: argument
 * Return: void
 */
int check_comment(char *str)
{
	int x = 0;

	while (str[x])
	{
		if (str[x] == ' ')
			continue;
		if (str[x] != '#')
			return (0);
		if (str[x] == '#')
			return (1);
		x++;
	}
	return (0);
}

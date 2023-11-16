#include "monty.h"

/**
 * split_string - splits a string into an array of tokens
 * @line: string
 * Return: array of tokens
 */

char **split_string(char *line)
{
	char *ptr, *str;
	char **str_arr = malloc(sizeof(char *) * 3);
	int x = 0;

	if (str_arr == NULL)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}

	str = line;
	ptr = _strsep(&str, " ");
	while (ptr != NULL && x < 2)
	{
		if (*ptr != '\0')
		{
			str_arr[x] = _strdup(ptr);
			if (str_arr[x] == NULL)
			{
				while (x >= 0)
				{
					free(str_arr[x]);
					x--;
				}
				free(str_arr);
			}
			x++;
		}
		ptr = _strsep(&str, " ");
	}
	str_arr[x] = NULL;
	return (str_arr);
}

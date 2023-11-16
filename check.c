#include "monty.h"

int check_4_alpha(char *str)
{
	int x, i;

	x = 0;
	i = 0;
	if (*str == '\n')
		return (0);
	for (i = 0; i < str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			x++;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			x++;
	}

	return (x);
}

int str_to_int(char *input)
{
	int result = 0;
	char *ptr = input;

	while (*ptr != '\0' && *ptr != '\n')
	{
		if (!(*ptr >= 48 && *ptr <= 57))
		{
			return (-1);
		}
		else
		{
			result = result * 10 + (*ptr - '0');
		}
		ptr++;
	}
	return (result);
}

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

int str_to_int(char *input, int *res)
{
	char *ptr = input;
	int sign = 1, x = 0;

	if (ptr == NULL)
		return (-1);
	for (; ptr[x] != '\0' && ptr[x] != '\n'; x++)
	{
		if (ptr[x] == '-' && x == 0)
		{
			sign = -1;
			continue;
		}
		if (!(ptr[x] >= 48 && ptr[x] <= 57))
			return (-1);
		*res = *res * 10 + (ptr[x] - '0');
	}
	*res = *res * sign;
	return (1);
}

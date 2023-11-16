#include "monty.h"

void write_err(char *str)
{
	write(2, str, strlen(str));
	free(str);
}

void malloc_error(void)
{
	char *str = "Error: malloc failed\n";

	write(2, str, strlen(str));
}

char *compose_err(char *str, unsigned int num)
{
	char *err = malloc(sizeof(char) * strlen(str)), *ptr;
	unsigned int x = 0;

	if (err == NULL)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}

	ptr = err;
	for (; str[x] != '\0'; x++)
	{
		if (str[x] == '%' && str[x + 1] == 'u')
		{
			*err++ = 48 + (signed)num;
			x++;
		}
		else
			*err++ = str[x];
	}
	*err = '\0';
	return (ptr);
}

char *compose_err_str(char *str, char *filename)
{
	char *err = malloc(sizeof(char) * (strlen(str) + strlen(filename) + 1));
	char *ptr;
	unsigned int x = 0;

	if (err == NULL)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}

	ptr = err;
	for (; str[x] != '\0'; x++)
	{
		if (str[x] == '%' && str[x + 1] == 's')
		{
			while (*filename != '\0')
				*err++ = *filename++;
			x++;
		}
		else
			*err++ = str[x];
	}
	*err = '\0';
	return (ptr);
}

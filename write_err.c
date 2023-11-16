#include "monty.h"

/**
 * write_err - writes an error msg to stdout
 * @str: string
 * Return: void
 */

void write_err(char *str)
{
	write(2, str, strlen(str));
	free(str);
}

/**
 * malloc_error - writes an error msg to stdout on malloc failure
 * Return: void
 */

void malloc_error(void)
{
	char *str = "Error: malloc failed\n";

	write(2, str, strlen(str));
}

/**
 * compose_err - composes a string from a string format and an integer
 * @str: string
 * @num: number
 * Return: on success, the composed string or NULL on failure
 */

char *compose_err(char *str, unsigned int num)
{
	char *err, *int_str;
	char *ptr;
	unsigned int x, y;

	int_str = convert_int_to_str(num);
	err = malloc(sizeof(char) * (strlen(str) + strlen(int_str)));
	if (err == NULL)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}
	ptr = err;
	x = y = 0;
	for (; str[x] != '\0'; x++)
	{
		if (str[x] == '%' && str[x + 1] == 'u')
		{
			while (int_str[y] != '\0')
				*err++ = int_str[y++];
			x++;
		}
		else
			*err++ = str[x];
	}
	*err = '\0';
	return (ptr);
}

/**
 * compose_err_str - composes a string from a string format and a string
 * @str: string format
 * @filename: string
 * Return: on success, the composed string or NULL on failure
 */

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

/**
 * convert_int_to_str - converts an integer to a string
 * @n: integer
 * Return: pointer to string
 */

char *convert_int_to_str(int n)
{
	int tmp = n;
	unsigned int len = 0, count = 1, x = 0;
	char *str;

	while (tmp > 9)
	{
		tmp /= 10;
		count *= 10;
	}
	tmp = n;
	if (n == 0)
		len++;
	while (tmp > 0)
	{
		tmp /= 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}
	for (; count >= 1; count /= 10)
	{
		str[x] = ((n / count) % 10) + 48;
		x++;
	}
	str[x] = '\0';
	return (str);
}

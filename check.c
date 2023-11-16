#include "monty.h"

/**
 * check_4_alpha - Checks if a string contains at least one
 * alphabetic character.
 * @str: Pointer to the string to be checked.
 *
 * Return: the amount of alphabeth if the string contains at
 * least one alphabetic character, 0 otherwise.
 */
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

/**
 * str_to_int - Converts a string to an integer.
 * @input: Pointer to the string to be converted.
 * @res: Pointer to the integer where the result will be stored.
 *
 * Return: 1 if the conversion is successful, 0 otherwise.
 */
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

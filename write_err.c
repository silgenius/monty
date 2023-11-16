#include "monty.h"

void write_err(char *str)
{
	write(2, str, strlen(str));
}

char *compose_err(char *str, int num)
{
	char *err = malloc(sizeof(str) * (strlen(str) - 1));

	if (err == NULL)
	{
		ex

#include "monty.h"

void (*check_opcode(char *str))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t opcode_list[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"NULL", NULL}
	};

	while (opcode_list[i].opcode != NULL)
	{
		if (strcmp(opcode_list[i].opcode, str) == 0)
			return opcode_list[i].f;
		i++;
	}

	return (NULL)
}

#include "monty.h"

void (*check_opcode(char *str))(stack_t **, unsigned int, char *)
{
	int i = 0;

	instruction_t opcode_list[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mul_func},
		{"mod", mod_func},
		{"pchar", pchar_func},
		{"pstr", pstr_func},
		{"rotl", rotl_func},
		{"rotr", rotr_func},
		{NULL, NULL}
	};

	while (opcode_list[i].opcode != NULL)
	{
		if (strcmp(opcode_list[i].opcode, str) == 0)
			return opcode_list[i].f;
		i++;
	}

	return (NULL);
}

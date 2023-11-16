#include "monty.h"

int interprete_opcode(stack_t **stack, char **str_arr, int line_no)
{
	char *ptr, *str;
	void (*opcode_func)(stack_t **, unsigned int);

	if (check_opcode(str_arr[0]) != NULL)
		opcode_func = check_opcode(str_arr[0]);
	else
	{
		/* not a valid opcode */
		str = compose_err("L%u: unknown instruction %s\n", line_no);
		ptr = compose_err_str(str, str_arr[0]);
		free(str);
		write_err(ptr);
		exit(EXIT_FAILURE);
	}

	/* now we have our function for command in the opcode_func and also ptr
	 * contains the int */
	opcode_func(stack, line_no);

	return (1);
}

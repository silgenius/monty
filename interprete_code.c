#include "monty.h"

int interprete_opcode(stack_t **stack, char **str_arr, int line_no)
{
	char *ptr, *str;

	if (check_opcode(str_arr[0]) != NULL)
		check_opcode(str_arr[0])(stack, line_no, str_arr[1]);
	else
	{
		str = compose_err("L%u: unknown instruction %s\n", line_no);
		ptr = compose_err_str(str, str_arr[0]);
		free(str);
		write_err(ptr);
		exit(EXIT_FAILURE);
	}
	return (1);
}

#include "monty.h"

/**
 * interprete_opcode - Interprets and executes an opcode.
 * @stack: Pointer to a pointer to the stack.
 * @str_arr: Pointer to an array of strings containing the opcode and arguments.
 * @line_no: The current line number being interpreted.
 *
 * Return: 1 if successful, 0 otherwise.
 */
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

#include "monty.h"

/**
 * mod_func - computes the rest of the division of the second top element by the top element.
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void mod_func(stack_t **stack, unsigned int line_number, char *data_n)
{
	stack_t *curr;
	char *str;
	int res;

	(void)data_n;
	curr = *stack;
	if (curr != NULL && curr->next != NULL)
	{
		if (curr->n == 0)
		{
			str = compose_err("L%u: division by zero\n",
					  line_number);
			write_err(str);
			exit(EXIT_FAILURE);
		}
		res = curr->next->n % curr->n;
		curr->next->n = res;
		pop_func(stack, line_number, "nil");
		return;
	}

	str = compose_err("L%u: can't mod, stack too short\n", line_number);
	write_err(str);
	exit(EXIT_FAILURE);
}

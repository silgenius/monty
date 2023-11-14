#include "monty.h"

/**
 * mod_func - computes the rest of the division of the second top element by the top element.
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * Return: void
 */

void mod_func(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	int res;

	curr = *stack;
	if (curr != NULL && curr->next != NULL)
	{
		if (curr->n == 0)
		{
			dprintf(2, "L%u: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		res = curr->next->n % curr->n;
		curr->next->n = res;
		pop_func(stack, line_number);
		return;
	}

	dprintf(2, "L%u: can't mod, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

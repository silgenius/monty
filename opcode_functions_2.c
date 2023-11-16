#include "monty.h"

/**
 * add_func - adds the top two elements of the stack
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * Return: void
 */

void add_func(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	int sum;

	curr = *stack;
	if (curr != NULL && curr->next != NULL)
	{
		sum = curr->n + curr->next->n;
		curr->next->n = sum;
		pop_func(stack, line_number);
		return;
	}

	dprintf(2, "L%u: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * nop_func - doesn't do anything
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * Return: void
 */

void nop_func(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub_func - subtacts the top element from the second top element
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * Return: void
 */

void sub_func(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	int sub;

	curr = *stack;
	if (curr != NULL && curr->next != NULL)
	{
		sub = curr->next->n - curr->n;
		curr->next->n = sub;
		pop_func(stack, line_number);
		return;
	}

	dprintf(2, "L%u: can't sub, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * div_func - divides the second top element of the stack by the first
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * Return: void
 */

void div_func(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	int res;

	curr = *stack;
	if (curr != NULL && curr->next != NULL)
	{
		res = curr->next->n / curr->n;
		curr->next->n = res;
		pop_func(stack, line_number);
		return;
	}

	dprintf(2, "L%u: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * mul_func - multiplies the second top element with the top element
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * Return: void
 */

void mul_func(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;
	int res;

	curr = *stack;
	if (curr != NULL && curr->next != NULL)
	{
		res = curr->n * curr->next->n;
		curr->next->n = res;
		pop_func(stack, line_number);
		return;
	}

	dprintf(2, "L%u: can't mul, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

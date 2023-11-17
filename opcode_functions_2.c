#include "monty.h"

/**
 * add_func - adds the top two elements of the stack
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void add_func(stack_t **stack, unsigned int line_number, char *data_n)
{
	stack_t *curr;
	char *str;
	int sum;

	(void)data_n;
	curr = *stack;
	if (curr != NULL && curr->next != NULL)
	{
		sum = curr->n + curr->next->n;
		curr->next->n = sum;
		pop_func(stack, line_number, "nil");
		return;
	}

	str = compose_err("L%u: can't add, stack too short\n", line_number);
	write_err(str);
	exit(EXIT_FAILURE);
}

/**
 * nop_func - doesn't do anything
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void nop_func(stack_t **stack, unsigned int line_number, char *data_n)
{
	(void)data_n;
	(void)stack;
	(void)line_number;
}

/**
 * sub_func - subtacts the top element from the second top element
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void sub_func(stack_t **stack, unsigned int line_number, char *data_n)
{
	stack_t *curr;
	char *str;
	int sub;

	(void)data_n;
	curr = *stack;
	if (curr != NULL && curr->next != NULL)
	{
		sub = curr->next->n - curr->n;
		curr->next->n = sub;
		pop_func(stack, line_number, "nil");
		return;
	}

	str = compose_err("L%u: can't sub, stack too short\n", line_number);
	write_err(str);
	exit(EXIT_FAILURE);
}

/**
 * div_func - divides the second top element of the stack by the first
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void div_func(stack_t **stack, unsigned int line_number, char *data_n)
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
		res = curr->next->n / curr->n;
		curr->next->n = res;
		pop_func(stack, line_number, "nil");
		return;
	}

	str = compose_err("L%u: can't div, stack too short\n", line_number);
	write_err(str);
	exit(EXIT_FAILURE);
}

/**
 * mul_func - multiplies the second top element with the top element
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void mul_func(stack_t **stack, unsigned int line_number, char *data_n)
{
	stack_t *curr;
	char *str;
	int res;

	(void)data_n;
	curr = *stack;
	if (curr != NULL && curr->next != NULL)
	{
		res = curr->n * curr->next->n;
		curr->next->n = res;
		pop_func(stack, line_number, "nil");
		return;
	}

	str = compose_err("L%u: can't mul, stack too short\n", line_number);
	write_err(str);
	exit(EXIT_FAILURE);
}

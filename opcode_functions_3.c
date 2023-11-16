#include "monty.h"

/**
 * mod_func - computes the rest of the division of the second top element by the
              top element.
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

/**
 * pchar_func - prints the char at the top of the stack
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void pchar_func(stack_t **stack, unsigned int line_number, char *data_n)
{
	stack_t *curr;
	char *str;

	(void)data_n;
	curr = *stack;
	if (curr != NULL)
	{
		if (curr->n < 0 || curr->n > 127)
		{
			str = compose_err("L%u: can't pchar, value out of range\n",
					  line_number);
			write_err(str);
			exit(EXIT_FAILURE);
		}
		printf("%c\n", curr->n);
		return;
	}

	str = compose_err("L%u: can't pchar, stack empty\n", line_number);
	write_err(str);
	exit(EXIT_FAILURE);
}

/**
 * pstr_func - prints the string starting at the top of the stack
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void pstr_func(stack_t **stack, unsigned int line_number, char *data_n)
{
	stack_t *curr;

	(void)line_number;
	(void)data_n;
	curr = *stack;
	while (curr != NULL)
	{
		if (curr->n <= 0 || curr->n > 127)
			break;
		printf("%c", curr->n);
		curr = curr->next;
	}
	printf("\n");
}

/**
 * rotl_func - rotates the stack to the top
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void rotl_func(stack_t **stack, unsigned int line_number, char *data_n)
{
	stack_t *curr, *tmp;

	(void)line_number;
	(void)data_n;
	curr = *stack;
	if (curr == NULL || curr->next == NULL)
		return;
	tmp = curr;
	curr->next->prev = curr->prev;
	*stack = curr = curr->next;;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = tmp;
	tmp->prev = curr;
	tmp->next = NULL;
}

/**
 * rotr_func - rotates the stack to the bottom
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void rotr_func(stack_t **stack, unsigned int line_number, char *data_n)
{
	stack_t *curr, *tmp;

	(void)line_number;
	(void)data_n;
	curr = *stack;
	if (curr == NULL || curr->next == NULL)
		return;
	while (curr->next->next != NULL)
		curr = curr->next;
	tmp = curr->next;
	tmp->prev = NULL;
	curr->next = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}

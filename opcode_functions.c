#include "monty.h"

/**
 * push_func - adds a value to the top of the stack
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void push_func(stack_t **stack, unsigned int line_number, char *data_n)
{
	stack_t *new_node;
	char *str;
	int n, res = 0;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return;
	n = str_to_int(data_n, &res);
	if (n == -1)
	{
		str = compose_err("L%u: usage: push integer\n", line_number);
		write_err(str);
		exit(EXIT_FAILURE);
	}
	new_node->n = res;
	new_node->prev = NULL;
	new_node->next = *stack;
	if ((*stack) != NULL)
		(*stack)->prev = new_node;
	(*stack) = new_node;
}

/**
 * pall_func - prints the values of the stack starting from the top
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void pall_func(stack_t **stack, unsigned int line_number, char *data_n)
{
	stack_t *curr = *stack;

	(void)data_n;
	(void)line_number;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * pint_func - prints the value at the top of the stack
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void pint_func(stack_t **stack, unsigned int line_number, char *data_n)
{
	stack_t *curr = *stack;
	char *str;

	(void)data_n;
	if (curr != NULL)
	{
		printf("%d\n", curr->n);
		return;
	}

	str = compose_err("L%u: can't pint, stack empty\n", line_number);
	write_err(str);
	exit(EXIT_FAILURE);
}

/**
 * pop_func - removes the top element of the stack
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void pop_func(stack_t **stack, unsigned int line_number, char *data_n)
{
	stack_t *curr = *stack;
	char *str;

	(void)data_n;
	if (curr != NULL)
	{
		if (curr->next != NULL)
		{
			curr->next->prev = NULL;
			*stack = curr->next;
		}
		else
			*stack = NULL;
		return;
	}

	str = compose_err("L%u: can't pop an empty stack\n", line_number);
	write_err(str);
	exit(EXIT_FAILURE);
}

/**
 * swap_func - swaps the top two elements of the stack
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void swap_func(stack_t **stack, unsigned int line_number, char *data_n)
{
	stack_t *curr, *first, *second;
	char *str;
	int tmp;

	(void)data_n;
	curr = *stack;
	if (curr != NULL && curr->next != NULL)
	{
		first = curr;
		second = curr->next;
		tmp = first->n;
		first->n = second->n;
		second->n = tmp;
		return;
	}

	str = compose_err("L%u: can't swap, stack too short\n", line_number);
	write_err(str);
	exit(EXIT_FAILURE);
}

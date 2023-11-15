#include "monty.h"

/**
 * push_func - adds a value to the top of the stack
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * Return: void
 */

void push_func(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return;
	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *head;
	if ((*head) != NULL)
		(*head)->prev = new_node;
	(*head) = new_node;
}

/**
 * pall_func - prints the values of the stack starting from the top
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * Return: void
 */

void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

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
 * Return: void
 */

void pint_func(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	if (curr != NULL)
	{
		printf("%d\n", curr->n);
		return;
	}

	dprintf(2, "L%u: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * pop_func - removes the top element of the stack
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * Return: void
 */

void pop_func(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

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

	dprintf(2, "L%u: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * swap_func - swaps the top two elements of the stack
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * Return: void
 */

void swap_func(stack_t **stack, unsigned int line_number)
{
	stack_t *curr, *first, *second;
	int tmp;

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

	dprintf(2, "L%u: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

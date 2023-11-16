#include "monty.h"

/**
 * stack_func - sets the behaviour of the program to stack
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void stack_func(stack_t **stack, unsigned int line_number, char *data_n)
{
	(void)stack;
	(void)line_number;
	(void)data_n;

	mode = 1;
}

/**
 * queue_func - sets the behaviour of the program to queue
 * @stack: pointer to the head of the double linked list
 * @line_number: command line number
 * @data_n: new_node data
 * Return: void
 */

void queue_func(stack_t **stack, unsigned int line_number, char *data_n)
{
	(void)stack;
	(void)line_number;
	(void)data_n;

	mode = 0;
}

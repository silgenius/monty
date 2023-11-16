#include "monty.h"

/**
 * free_stack - frees a stack_t
 * @head: head of the list
 * Return: void
 */

void free_stack(stack_t *head)
{
	stack_t *tmp, *curr = head;

	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	head = NULL;
}

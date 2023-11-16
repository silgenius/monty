#include "monty.h"

/**
 * _realloc - reallocates a block of memory using malloc and free
 * @ptr: pointer to memory previously allocated
 * @old_size: size of allocated space for ptr
 * @new_size: new size of memory block
 * Return: void
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int x;
	char *pointer, *temp;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		pointer = malloc(new_size);
		if (pointer == NULL)
			return (NULL);
		free(ptr);
		return (pointer);
	}
	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	pointer = malloc(new_size);
	if (pointer == NULL)
		return (NULL);
	temp = ptr;
	for (x = 0; x < (new_size > old_size ? old_size : new_size); x++)
		pointer[x] = temp[x];
	free(ptr);
	return (pointer);
}

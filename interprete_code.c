#include "monty.h"

int interprete_opcode(char *str_arr, int line_no, stack_t **head_ptr)
{
	char *ptr, *str;
	int x = 0;
	void (*opcode_func)(stack_t **, unsigned int);

	str = str_arr;
	ptr = strtok(str, " ");
	while (ptr  != NULL && x < 1)
	{
		if (*ptr == '\0')
		{
			ptr = strtok(NULL, " ");
			continue;
		} 

		if (x == 0)
		{
			if (check_opcode(ptr) != NULL)
				opcode_func = check_opcode(ptr);
			else
				return (0); /* not a valid opcode */
		}
		ptr = strtok(NULL, " ");
		x++;
	}
	int n = str_to_int(ptr);
	/* now we have our function for command in the opcode_func and also ptr
	 * contains the int */
	opcode_func(head_ptr, line_no);

	return (1);
}


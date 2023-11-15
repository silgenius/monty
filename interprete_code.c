#include "monty.h"


int interprete_opcode(char *str_arr, int line_no)
{
	char *ptr, *str;
	int x = 0;
	void (*opcode_func)(stack_t **, unsigned int);

	str = str_arr;
	ptr = strsep(&str, " ");
	while (ptr != NULL && x < 2)
	{
		if (x == 0)
		{
			if (check_opcode(ptr) != NULL)
				opcode_func = check_opcode(ptr);
			else
				return (0); /* not a valid opcode */
		}

		ptr = strsep(&str, " ");
	}
	/* now we have our function for command in the opcode_func and also ptr
	 * contains the int */
	opcode_func(&head, line_no);

	return (1);
}


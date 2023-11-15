#include "monty.h"

void interprete_opcode(char **str_arr)
{
	char *ptr;
	int x = 0;
	void (*opcode_func)(stack_t **, unsigned int)

	str = str_arr[x];
	while (str != NULL)
	{
		ptr = strsep(str_arr[x], " ");
		while (ptr != NULL)
		{
			if (check_opcode(ptr) != NULL)
				opcode_func = check_opcode(ptr);
			ptr = strsep(str_arr[x], " ");
		}

		/* continue later */
	}
}


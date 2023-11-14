#include "monty.h"

void open_file(char *file)
{
	FILE *fptr;
	char **str_arr[BUFF_SIZE];

	if ((fptr = fopen(file, "r")) == NULL)
	{
		dprintf(2, "Error: Can't open file <file>\n");
		exit(EXIT_FAILURE);
	}
}

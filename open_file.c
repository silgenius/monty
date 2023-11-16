#include "monty.h"

void open_file(char *filename)
{
	FILE *fptr;
	char *line = NULL;
	size_t len = 0, read;
	int line_number = 1;
	stack_t *head;

	head = NULL;
	len = 0;

	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fptr)) != -1)
	{
		if (check_4_alpha(line) == 0)
			continue;
		interprete_opcode(line, line_number, &head);
		line_number++;
	}

	if (read == -1)
		exit(EXIT_FAILURE);
	free(line);
	fclose(fptr);
}

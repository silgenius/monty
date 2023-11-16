#include "monty.h"

void open_file(char *filename)
{
	FILE *fptr;
	char *line = NULL;
	ssize_t len = 0;
	size_t read;
	int line_number = 1;

	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = read_line(&line, &len, fptr)) != -1)
	{
		interprete_opcode(line, line_number);
		line_number++;
	}

	if (read == -1)
		exit(EXIT_FAILURE);
	free(line);
	fclose(fptr);
}

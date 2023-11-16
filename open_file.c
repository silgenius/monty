#include "monty.h"

void open_file(char *filename)
{
	FILE *fptr;
	char *line, *str;
	char **str_arr;
	ssize_t len = 1024, read;
	int line_number = 1;
	stack_t *stack = NULL;

	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		str = compose_err_str("Error: Can't open file %s\n", filename);
		write_err(str);
		exit(EXIT_FAILURE);
	}

	line = malloc(sizeof(char) * len);
	if (line == NULL)
	{
		malloc_error();
		exit(EXIT_FAILURE);
	}

	while ((read = read_line(&line, &len, fptr)) != -1)
	{
		str_arr = split_string(line);
		interprete_opcode(&stack, str_arr, line_number);
		line_number++;
	}

	if (read == -1)
		exit(EXIT_FAILURE);
	free(line);
	fclose(fptr);
}

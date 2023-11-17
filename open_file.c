#include "monty.h"

/**
 * open_file - Opens a file with the specified filename.
 * @filename: Pointer to the string containing the filename.
 *
 * This function attempts to open the file with the given filename.
 * If the file opening is successful, it performs further operations
 * related to file handling.
 */
void open_file(char *filename)
{
	FILE *fptr;
	char *line, *str;
	char **str_arr;
	ssize_t len = 64, read = 0;
	int line_number = 1;
	stack_t *stack = NULL;

	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		str = compose_err_str("Error: Can't open file %s\n", filename);
		write_err(str);
		exit(EXIT_FAILURE);
	}
	while (read != -1)
	{
		line = malloc(sizeof(char) * len);
		if (line == NULL)
		{
			malloc_error();
			exit(EXIT_FAILURE);
		}
		read = read_line(&line, &len, fptr);
		if (read > 0)
		{
			if (check_comment(line) == 1)
			{
				free(line);
				continue;
			}
			str_arr = split_string(line);
			interprete_opcode(&stack, str_arr, line_number);
			free_str_arr(str_arr);
		}
		free(line);
		line_number++;
	}
	free_stack(stack);
	fclose(fptr);
}

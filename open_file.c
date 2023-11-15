#include "monty.h"

char **open_file(char *filename)
{
	FILE *fptr;
	char *line = NULL;
	size_t len = 0, x = 0;
	ssize_t read, i, j, line_len;
	char *input = malloc(sizeof(char) * 15);
	char **str_arr = malloc(sizeof(char) * BUFF_SIZE);

	len = 0;

	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	if (input == NULL || str_arr == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, fptr)) != -1)
	{
		line_len = strlen(line);
		for (i = 0, j = 0; i < line_len; i++)
		{
			if (line[i] != ' ' || (i > 0 && line[i - 1] != ' '))
				input[j++] = line[i];
		}
		input[j] = '\0';
		i = 0;
		j = 0;

		str_arr[x++] = strdup(input);
	}
	str_arr[x] = NULL;

	if (read == -1)
		exit(EXIT_FAILURE);
	free(line);
	free(input);

	return (str_arr);
}

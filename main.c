#include "monty.h"

int mode = 1;

/**
 * main - Entry point for the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of strings containing the command-line arguments.
 */
int main(int argc, char *argv[])
{
	char *str = "USAGE: monty file\n";

	if (argc != 2)
	{
		write(2, str, strlen(str));
		exit(EXIT_FAILURE);
	}

	open_file(argv[1]);

	return (0);
}

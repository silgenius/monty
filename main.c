#include "monty.h"

int mode = 1;

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

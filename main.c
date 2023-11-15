#include "monty.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	open_file(argv[1]);

	return (0);
}

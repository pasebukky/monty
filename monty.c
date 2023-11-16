#define _POSIX_C_SOURCE 200809L
#include "monty.h"

context_t context = {NULL, NULL, NULL};

/**
 * main - Monty bytecode interpreter
 *
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success
 *
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t line_number = 0, size = 0;
	ssize_t chars_read = 0;
	mstack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}


	while (chars_read != -1)
	{
		chars_read = getline(&line, &size, file);
		line_number++;
		/*printf("%d\n", (int)chars_read);*/
		if (chars_read > 1)
			exec_monty(line, &stack, line_number, file);
	}

	/* free_stack(stack); */
	fclose(file);
	return (0);
}

#include "monty.h"
 
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
char line[MAX_LINE_LENGTH];
size_t line_number = 0;
stack_t *stack = NULL;

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

initialize_context(file, NULL, NULL);

while (fgets(line, sizeof(line), file) != NULL)
{
	line_number++;
	exec_monty(line, &stack, line_number, file);
}

/* free_stack(stack); */
fclose(file);
free_context();
return (0);
}

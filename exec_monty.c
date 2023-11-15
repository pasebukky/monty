#include "monty.h" 

/**
 * exec_monty - Executes monty instructions
 *
 * @line: Line of monty bytecode file read
 * @stack: Double pointer to the stack
 * @line_number: Line number in the monty bytecode file
 * @file: Pointer to the file being processed
 * Return: 0 on success
 *
 */

int exec_monty(char *line, stack_t **stack, size_t line_number, FILE *file)
{
char *op;
instruction_t ops[] = INSTRUCTIONS_X; /* Assuming INSTRUCTIONS_X is defined */
size_t i = 0;

/* Tokenize the line to extract opcode and argument */
op = strtok(line, " \t\n"); /* Tokenize the line using whitespace characters */

if (!op)
	return (0);

if (op[0] == '#')
	return (0);  /* Ignore comments */

context.arg = strtok(NULL, " \t\n");  /* Extract the argument */

/* Iterate through the array of instructions to find a match */
while (ops[i].opcode && op)
{
	if (strcmp(op, ops[i].opcode) == 0)
	{
		ops[i].f(stack, line_number);  /* Execute the instruction */
		return (0);
	}
	i++;
}
 
/* Error handling if no match is found */
if (op && ops[i].opcode == NULL)
{
	fprintf(stderr, "L%lu: usage: push integer\n", line_number);
	/* free(line); */
	/*free_stack(*stack); Assuming free_stack takes a double pointer */
	fclose(file);
	/* free_context(); */
	exit(EXIT_FAILURE);
}
return (0);
}

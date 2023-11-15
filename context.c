#include "monty.h"

context_t context;

/**
 * initialize_context - Initializes the context variables.
 * @file: File pointer.
 * @arg: Argument string.
 * @line: Line string.
 *
 */

void initialize_context(FILE *file, char *arg, char *line)
{
	context.file = file;
	context.arg = arg;
	context.line = line;
}







/**
 * free_context - Frees memory allocated for context variables.
 *
 */

void free_context(void)
{
if (context.file != NULL)
{
	fclose(context.file);
	context.file = NULL;
}

if (context.arg != NULL)
{
	free(context.arg);
	context.arg = NULL;
}

if (context.line != NULL)
{
	free(context.line);
	context.line = NULL;
}
}



/**
 * free_stack - Frees memory allocated for a stack.
 * @stack: Pointer to the stack.
 *
 */

void free_stack(stack_t *stack)
{
while (stack)
{
	stack_t *temp = stack;

	stack = stack->next;
	free(temp);
}
}

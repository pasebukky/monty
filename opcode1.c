#include "monty.h"

/**
 * x_push - Pushes an element onto the stack
 *
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty bytecode file
 *
 */

void x_push(mstack_t **stack, unsigned int line_number)
{
mstack_t *new_node;
int num;
char *arg;

/* Check if the argument provided is a valid integer */
if (!context.arg)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

arg = context.arg;
if (*arg == '-')
{
	arg++;
}
while(*arg)
{
	if (!isdigit(*arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	arg++;
}

num = atoi(context.arg);

/* Allocate memory for a new stack node */
new_node = malloc(sizeof(mstack_t));

if (!new_node)
{
	perror("Error: malloc failed");
	exit(EXIT_FAILURE);
}

/* Set the new nodes value */
new_node->n = num;
new_node->prev = NULL;
new_node->next = *stack;

/* Update previous pointer of the existing stack top */
if (*stack)
	(*stack)->prev = new_node;

/* Update the stack top pointer */
*stack = new_node;
}





/**
 * x_pall - Prints all values on the stack
 *
 * @stack: Pointer to the stack
 * @line_number: Line number in the Monty bytecode file
 *
 */

void x_pall(mstack_t **stack, unsigned int line_number)
{
mstack_t *current;

/* Check if the stack is empty */
if (*stack == NULL)
{
	fprintf(stderr, "L%u: stack empty\n", line_number);
	exit(EXIT_FAILURE);
}

/* Traverse the stack and print each element */
current = *stack;

while (current)
{
	printf("%d\n", current->n);
	current = current->next;
}
}

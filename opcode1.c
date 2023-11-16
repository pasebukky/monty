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

if (!context.arg)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	free(context.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
arg = context.arg;
if (*arg == '-')
	arg++;
while (*arg)
{
	if (!isdigit(*arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(context.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	arg++;
}
num = atoi(context.arg);
new_node = malloc(sizeof(mstack_t));
if (!new_node)
{
	perror("Error: malloc failed");
	exit(EXIT_FAILURE);
}
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
(void)line_number;

/* Traverse the stack and print each element */
current = *stack;

if (current == NULL)
	return;
while (current)
{
	printf("%d\n", current->n);
	current = current->next;
}
}



/**
 * x_pint - Prints the value at the top of the stack, followed by a new line.
 *
 * @stack: A pointer to the stack.
 * @line_number: The line number where the pint opcode is encountered.
 *
 */

void x_pint(mstack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}






/**
* x_pop - he opcode pop removes the top element of the stack.
* @stack: Pointer to the stack
* @line_number: Line number in the Monty bytecode file
*
*/

void x_pop(mstack_t **stack, unsigned int line_number)
{
mstack_t *current;

if (*stack == NULL)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	free_stack(*stack);
	exit(EXIT_FAILURE);

}
current = *stack;
*stack = current->next;
free(current);
}






/**
 * x_swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 *
 */

void x_swap(mstack_t **stack, unsigned int line_number)
{
mstack_t *temp;

if (*stack == NULL || (*stack)->next == NULL)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	/* fclose(context.file); */
	free_stack(*stack);
	/* free(context.line); */
	exit(EXIT_FAILURE);
}
temp = (*stack)->next;
(*stack)->next = temp->next;
temp->next = *stack;
*stack = temp;
}


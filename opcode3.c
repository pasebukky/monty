#include "monty.h"

/**
 * x_mod - Computes the rest of the division of the second top element
 * by the top element.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 *
 */

void x_mod(mstack_t **stack, unsigned int line_number)
{
mstack_t *temp, *second_elem;

if (*stack == NULL || (*stack)->next == NULL)
{
	fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

temp = *stack;
second_elem = temp->next;

if (temp->n == 0)
{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
second_elem->n %= temp->n;
*stack = second_elem;
free(temp);
}



/**
 * x_pchar - Prints the char at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 *
 */

void x_pchar(mstack_t **stack, unsigned int line_number)
{
mstack_t *top;

if (*stack == NULL)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

top = *stack;

while (top->prev)
	top = top->prev;

if (isalpha(top->n) == 0)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n",
	line_number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
printf("%c\n", top->n);
}

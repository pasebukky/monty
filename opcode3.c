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
second_elem->n = temp->n % second_elem->n;
*stack = second_elem;
free(temp);
}


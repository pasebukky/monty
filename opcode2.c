#include "monty.h"

/**
 * x_add - Adds the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 *
 */

void x_add(mstack_t **stack, unsigned int line_number)
{
mstack_t *temp;

if (*stack == NULL || (*stack)->next == NULL)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
temp = *stack;
(*stack)->next->n += (*stack)->n;
*stack = (*stack)->next;
(*stack)->prev = NULL;
free(temp);
}



/**
 * x_nop - Does nothing.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 *
 */

void x_nop(mstack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}




/**
 * x_sub - Subtracts the top element of the stack from the second top element.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 *
 */

void x_sub(mstack_t **stack, unsigned int line_number)
{
mstack_t *temp;

if (*stack == NULL || (*stack)->next == NULL)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
temp = *stack;
(*stack)->next->n -= (*stack)->n;
*stack = (*stack)->next;
(*stack)->prev = NULL;
free(temp);
}

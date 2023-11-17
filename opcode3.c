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





/**
 * x_pstr - Prints the string starting at the top of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 *
 */

void x_pstr(mstack_t **stack, unsigned int line_number)
{
mstack_t *current;
(void)line_number;

for (current = *stack; current && current->n != 0 &&
isalpha(current->n); current = current->next)
{
	putchar((char)(current->n));
}
putchar('\n');
}



/**
* x_rotl - a function that implements the rotl opcode.
* @stack: Pointer to the stack.
* @line_number: Line number in the Monty bytecode file.
*
* Description: The opcode rotl rotates the stack to the top.
*/

void x_rotl(mstack_t **stack, unsigned int line_number)
{
	mstack_t *left;
	mstack_t *right;

	(void) line_number;

	/**
	 * Error handling:
	 * if stack is empty or there's only one element int the stack
	 * return early
	 */
	if (!*stack || !(*stack)->next)
		return;

	/**
	 * left and right are two pointers to stacks that now point to
	 * the head of the stack
	 */
	left = right = *stack;

	/* Move the right pointer to the rightmost node */
	while (right->next)
		right = right->next;

	/* create a circular linked list */
	right->next = left;
	left->prev = right;

	/**
	 * move stack head to point to the second node effectively
	 * begining the rotation
	 */
	*stack = left->next;

	/* bread the circular linked list */
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}




























#include "monty.h"
/**
* free_stack - frees a doubly linked list
* @stack: stack of the stack
*/
void free_stack(mstack_t *stack)
{
	mstack_t *temp;

	temp = stack;
	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

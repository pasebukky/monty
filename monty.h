#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1024

/**
 * Macro to define all instruction_t structs with functions prefixed by "x_"
 */
#define INSTRUCTIONS_X \
	{ \
		{"push", x_push}, \
		{"pall", x_pall}, \
		{"pint", x_pint}, \
		{"pop", x_pop}, \
		{"swap", x_swap}, \
		{"add", x_add}, \
		{"nop", x_nop}, \
		{"sub", x_sub}, \
		{"div", x_div}, \
		{"mul", x_mul}, \
		{"mod", x_mod}, \
		{"pchar", x_pchar}, \
		{NULL, NULL} \
	}

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} mstack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(mstack_t **stack, unsigned int line_number);
} instruction_t;


/**
* main - entry point
* @n: number..
*
* Description: a function that prints the alphabet
* Return: 0 (success)
*/
typedef struct context_s
{
	FILE *file;
	char *arg;
	char *line;
} context_t;

extern context_t context;



/* Function Prototypes */
int exec_monty(char *line, mstack_t **stack, size_t line_number, FILE *file);
void free_context();
void x_push(mstack_t **stack, unsigned int line_number);
void x_pall(mstack_t **stack, unsigned int line_number);
void x_pint(mstack_t **stack, unsigned int line_number);
void x_pop(mstack_t **stack, unsigned int line_number);
void x_swap(mstack_t **stack, unsigned int line_number);
void x_add(mstack_t **stack, unsigned int line_number);
void x_nop(mstack_t **stack, unsigned int line_number);
void x_sub(mstack_t **stack, unsigned int line_number);
void x_div(mstack_t **stack, unsigned int line_number);
void x_mul(mstack_t **stack, unsigned int line_number);
void x_mod(mstack_t **stack, unsigned int line_number);
void x_pchar(mstack_t **stack, unsigned int line_number);
void x_pstr(mstack_t **stack, unsigned int line_number);
void x_rotl(mstack_t **stack, unsigned int line_number);
void x_rotr(mstack_t **stack, unsigned int line_number);
void x_queue(mstack_t **stack, unsigned int line_number);
void x_stack(mstack_t **stack, unsigned int line_number);



/* util.c */
void free_stack(mstack_t *stack);








#endif

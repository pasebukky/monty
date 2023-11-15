#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>



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
		{"pstr", x_pstr}, \
		{"rotl", x_rotl}, \
		{"rotr", x_rotr}, \
		{"queue", x_queue}, \
		{"stack", x_stack}, \
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
} stack_t;

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
        void (*f)(stack_t **stack, unsigned int line_number);
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

/* Function Prototypes */
bool _opcode(char *str);
void x_push(stack_t **stack, unsigned int line_number);
void x_pall(stack_t **stack, unsigned int line_number);
void x_pint(stack_t **stack, unsigned int line_number);
void x_pop(stack_t **stack, unsigned int line_number);
void x_swap(stack_t **stack, unsigned int line_number);
void x_add(stack_t **stack, unsigned int line_number);
void x_nop(stack_t **stack, unsigned int line_number);
void x_sub(stack_t **stack, unsigned int line_number);
void x_div(stack_t **stack, unsigned int line_number);
void x_mul(stack_t **stack, unsigned int line_number);
void x_mod(stack_t **stack, unsigned int line_number);
void x_pchar(stack_t **stack, unsigned int line_number);
void x_pstr(stack_t **stack, unsigned int line_number);
void x_rotl(stack_t **stack, unsigned int line_number);
void x_rotr(stack_t **stack, unsigned int line_number);
void x_queue(stack_t **stack, unsigned int line_number);
void x_stack(stack_t **stack, unsigned int line_number);









#endif

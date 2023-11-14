#include "monty.h"




bool _opcode(char *str)
{
char *opcode = {"push", "pall", "pint", "pop", "swap", "add", "nop", "sub", "div", "mul", "mod", "pchar", "pstr", "rotl", "rotr", "stack", "queue"};

int i;

for (i = 0; opcode[i] != NULL; i++)
{
	if (strcmp(opcode[i], str) == 0)
		return (1);
}
return (0);
}

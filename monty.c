#include "monty.h"







int main(int argc, char *argv[])
{
FILE *fd;

if (argc != 2)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

fd = fopen(argv[1], "r");

if (fd == NULL)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit(EXIT_FAILURE);
}

if (!_opcode(argv[1]))
{
	fprint(stderr, "L<line_number>: unknown instruction <opcode>\n");
	exit(EXIT_FAILURE);
}





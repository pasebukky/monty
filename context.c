#include "monty.h"

context_t context;

void initialize_context(FILE *file, char *arg, char *line) 
{
	context.file = file;
	context.arg = arg;
	context.line = line;
}

void free_context() 
{
if (context.file != NULL) 
{
	fclose(context.file);
	context.file = NULL;
}

if (context.arg != NULL)
{
	free(context.arg);
	context.arg = NULL;
}

if (context.line != NULL)
{
	free(context.line);
	context.line = NULL;
}
}

//exec.c


int exec(char *line, stack_t **stack, size_t line_number, FILE *file)
{
	//var decs..
	
							  opcode  f	
	instruction_t ops[] = INSTRUCTIONS_X;  ops[0] -> {"push", x_push}
	int i = 0;
	
	// line -> push 8;
	// line1 -> prush;

	op = strtok(line, " \t\n");     -> prush 
	if (op[0] == '#')
		return (0);

	context.arg = strtok(NULL, " \t\n"); ->NULL
	while (ops[i].opcode && op)
	{
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return (0);
		}
		i++
	}

	//otherwise erro code below
	if (op && ops[i].opcode == NULL)
	{
		fprintf(stderr, L<line_number>: usage: push integer);
		free line;
		free_stack;
		fclose(file);
		exit failure;
	}

}

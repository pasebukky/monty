include monty.h



int main(....)
{
	//var declarations and init..
	FILE *file;
	ssize_t chars_read;
	char *line = NULL;
	size_t n = 0, line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		print error;
		exit failure;
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		print error;
		exit failure;
	}
	
	while ((chars_read = getline(&line, &n, file)) != -1)
	{
		line_number++;
	
		if (chars_read > 0)
			exec(line, &stack, line_number, file)
	}
	free(line);
	free_stack(stack);
	return (0);
}




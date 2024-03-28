#include "monty.h"
global_var var = {NULL, NULL, NULL};
/**
 * main - monty code interpreter
 * @argc: argument counter
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *args;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	var.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		args = NULL;
		read_line = getline(&args, &size, file);
		var.args = args;
		line_number++;
		if (read_line > 0)
		{
			execute(args, &stack, line_number, file);
		}
		free(args);
	}
	m_free(stack);
	fclose(file);
	return (0);
}

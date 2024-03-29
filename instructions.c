#include "monty.h"
/**
 * execute - executes the opcode
 * @args: arguments
 * @stack: the stack being evaluated
 * @line_number: the line number in the file
 * @file: pointer to the monty file
 *
 * Return: an integer
 */
int execute(char *args, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t instructions[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *code;

	code = strtok(args, " \n\t");
	var.line = strtok(NULL, " \n\t");
	while (instructions[i].opcode && code != NULL)
	{
		if (strcmp(code, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (code && instructions[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, code);
		fclose(file);
		free(args);
		m_free(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

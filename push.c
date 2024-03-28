#include "monty.h"
/**
 * m_push - pushes an element to the stack
 * @stack: the stack being evaluated
 * @line_number: the line number in the file
 *
 */
void m_push(stack_t **stack, unsigned int line_number)
{
	int n;
	int flag = 0;
	int i = 0;

	if (var.line)
	{
		if (var.line[0] == '-')
			i++;
		for (; var.line[i] != '\0'; i++)
		{
			if (var.line[i] > 57 || var.line[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(var.file);
			free(var.args);
			m_free(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(var.file);
		free(var.args);
		m_free(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(var.line);
	add_node(stack, n);
}

#include "monty.h"
/**
 * m_pint - prints the value at the top of the stack, followed by a newline
 * @stack: the stack being evaluated
 * @line_number: the line_number in the file
 *
 */
void m_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		m_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

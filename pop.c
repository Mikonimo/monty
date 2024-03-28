#include "monty.h"
/**
 * m_pop - removes the top element of the stack
 * @stack: the stack being evaluated
 * @line_number: the line_number in the file
 *
 */
void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		m_free(*stack);
		exit(EXIT_FAILURE);
	}
	*stack = curr->next;
	free(curr);
}

#include "monty.h"
/**
 * m_swap - swaps the top two elements of the stack
 * @stack: the stack being evaluated
 * @line_number: the line number in the file
 *
 */
void m_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int temp;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		m_free(*stack);
		exit(EXIT_FAILURE);
	}
	temp = curr->n;
	curr->n = curr->next->n;
	curr->next->n = temp;
}

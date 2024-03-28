#include "monty.h"
/**
 * m_add - adds the top two elements of the stack
 * @stack: the stack being evaluated
 * @line_number: line number in the file
 *
 */
void m_add(stack_t **stack, unsigned int line_number)
{
    stack_t *curr = *stack;
    int result;

    if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		m_free(*stack);
		exit(EXIT_FAILURE);
	}
    result = curr->n + curr->next->n;
    curr->next->n = result;
    *stack = curr->next;
    free(curr);
}

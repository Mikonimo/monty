#include "monty.h"
/**
 * m_push - pushes an element to the stack
 * @stack: the stack being evaluated
 * @line_number: line number where the instruction appears
 *
 */
void m_push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/*node->n = */
	node->prev = NULL;
	node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = node;
	}
	*stack = node;
	line_number++;
}

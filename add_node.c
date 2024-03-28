#include "monty.h"
/**
 * add_node - add node to the top of the stack
 * @stack: the stack being evaluated
 * @n: an integer
 *
 */
void add_node(stack_t **stack, int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->prev = NULL;
	node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = node;
	}
	*stack = node;
}

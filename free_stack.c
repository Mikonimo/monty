#include "monty.h"
/**
 * m_free - frees the doubly linked stack list
 * @head: the head of the stack
 *
 */
void m_free(stack_t *head)
{
	stack_t *curr = head;
	stack_t *next_node;

	while (curr != NULL)
	{
		next_node = curr->next;
		free(curr);
		curr = next_node;
	}
}

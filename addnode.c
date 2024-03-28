#include "monty.h"
/**
 * addnode - adds a new node at the end of the stack or queue
 * @head: the head pointer of the list
 * @n: an integer
 *
 */
void addnode(stack_t **head, const int n)
{
	stack_t *curr;
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->next = NULL;
	if (*head == NULL)
	{
		*head = node;
		node->prev = NULL;
	}
	else
	{
		curr = *head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = node;
		node->prev = curr;
	}
}

#include "monty.h"
/**
 * m_pall - prints all the values on the stac,starting from the top of the stack.
 * @stack: the stack being evaluated
 * @line_number: the line_number in the file
 *
*/
void m_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *h = *stack;
    (void)line_number;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}
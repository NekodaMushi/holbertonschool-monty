#include "monty.h"

/**
 * _pop - fct that removes top element of stack
 * @stack: head of stack
 * @line_number: number of line
 */

void _pop(ostack_t **stack, unsigned int line_number)
{
	ostack_t *tmp = *stack;

	if (*stack == NULL)
	{
		error_handle("L%u: can't pop an empty stack\n", line_number);
		return;
	}

	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}

#include "monty.h"

/**
 *_pint - print the value at the top of the stack
 * @stack: head of linked list
 * @line_number: line number in file
 */

void _pint(ostack_t **stack, unsigned int line_number)
{
	ostack_t *head = *stack;

	if (*stack == 0)
	{
		error_handle("L%d: can't pint, stack empty\n", line_number);
		return;
	}
	printf("%d\n", head->n);
}

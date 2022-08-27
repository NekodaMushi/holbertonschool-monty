#include "monty.h"
/**
 * _swap - swaps the top two elements of the stack
 * @stack: head of the linked list
 * @line_number: line's number in file
 * Return: Nothing
 */
void _swap(ostack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
	{
		error_handle("L%d: can't swap, stack too short\n", line_number);
		return;
	}
}

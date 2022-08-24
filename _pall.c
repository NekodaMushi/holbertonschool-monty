#include "monty.h"
/**
 * _pall - print all
 * @stack: the linked list
 * @line_number: number of line
 * Return: Nothing
 */
void _pall(ostack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_dlistint(*stack);
}

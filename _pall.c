#include "monty.h"

void _pall(ostack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_dlistint(*stack);
}

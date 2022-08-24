#include "monty.h"

int check_digit(char *svalue, unsigned int line_number)
{
	int i = 0;

	if (!svalue)
		error_handle("L%d: usage: push integer\n", line_number);

	while (svalue[i])
	{
		if (isdigit(svalue[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void _push(ostack_t **stack, unsigned int line_number)
{
	char *svalue = strtok(NULL, "\n\t ");

	if (check_digit(svalue, line_number))
	{
		add_dnodeint(stack, atoi(svalue));
	}
	else
		error_handle("L%d: usage: push integer\n", line_number);
}

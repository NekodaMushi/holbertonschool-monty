#include "monty.h"
/**
 * check_digit - Check if arg is a digit
 * @svalue: Value used
 * @line_number: number of line
 * Return: 1 or 0 depend if succeeded or not
 */
int check_digit(char *svalue, unsigned int line_number)
{
	int i = 0;

	if (!svalue)
		error_handle("L%d: usage: push integer\n", line_number);

	while (svalue[i])
	{
		if ((svalue[i]) == '-' && i == 0)
			i++;
		if (isdigit(svalue[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
/**
 * _push - push node at top of the list
 * @stack: the linked list
 * @line_number: number of line
 * Return: Nothing
 */
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

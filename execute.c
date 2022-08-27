#include "monty.h"
/**
 * execute - Check and do instruction from file
 * @stack: the linked list
 * @token: token used as command
 * @line_number: number of line
 * Return: Nothing
 */
void execute(ostack_t **stack, char *token, unsigned int line_number)
{
	int i = 0;
	instruction_t search[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{NULL, NULL}};

	if (!token)
		return;
	while (search[i].opcode != NULL)
	{
		if (strcmp(search[i].opcode, token) == 0)
		{
			search[i].f(stack, line_number);
			return;
		}
		i++;
	}
	error_handle("L%d: unknown instruction %s\n", line_number, token);
}

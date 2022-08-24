#include "monty.h"
/**
 * _free - fct freing arguments and close file
 * @stack: the linked list
 * @fd: the file to close
 * Return: None
 */
void _free(ostack_t *stack, FILE *file)
{
	ostack_t *tmp = stack;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	fclose(file);
}

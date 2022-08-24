#include "monty.h"

void execute(ostack_t **stack, char *token, unsigned int line_number)
{
	int i = 0;
	instruction_t search[] = {
		{"push", _push},
		{"pall", _pall},
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

int main(int argc, char const *argv[])
{
	FILE *file = NULL;
	char buffer[1024];
	unsigned int line_number = 1;
	ostack_t *stack = NULL;
	ostack_t *tmp = stack;

	if (argc != 2)
		error_handle("USAGE: monty file\n", NULL);

	file = fopen(argv[1], "r");
	if (!file)
		error_handle("Error: Can't open file %s\n", argv[1]);

	while (fgets(buffer, 1024, file) != NULL)
	{
		buffer[strlen(buffer) - 1] = '\0';
		if (strlen(buffer) > 0)
			execute(&stack, strtok(buffer, "\n\t "), line_number);
		line_number++;
	}
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	fclose(file);
	return 0;
}

#include "monty.h"
/**
 * main - First call of monty program
 * @argc: argument counter
 * @argv: argument value
 * Return: Nothing
 */
int main(int argc, char const *argv[])
{
	FILE *file = NULL;
	char buffer[1024];
	unsigned int line_number = 1;
	ostack_t *stack = NULL;

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
	_free(stack, file);
	return (0);
}

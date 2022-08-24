#include "monty.h"
/**
 * error_handle - Fct dealing with errors
 *
 * @format: format used
 *
 * Return: Nothing
 */
void error_handle(char *format, ...)
{
	va_list args;

	va_start(args, format);
	vdprintf(STDERR_FILENO, format, args);
	va_end(args);

	exit(EXIT_FAILURE);
}

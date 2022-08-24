#include "monty.h"

void error_handle(char *format, ...)
{
	va_list args;

	va_start(args, format);
	vdprintf(STDERR_FILENO, format, args);
	va_end(args);

	exit(EXIT_FAILURE);
}

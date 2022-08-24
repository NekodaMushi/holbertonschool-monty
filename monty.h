#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} ostack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(ostack_t **stack, unsigned int line_number);
} instruction_t;

/* UTILS */
void error_handle(char *format, ...);

/* LIST_UTILS */
ostack_t *add_dnodeint(ostack_t **head, const int n);
size_t print_dlistint(const ostack_t *h);

/* OPCODES */
void _push(ostack_t **stack, unsigned int line_number);
void _pall(ostack_t **stack, unsigned int line_number);

#endif /* MONTY_H */

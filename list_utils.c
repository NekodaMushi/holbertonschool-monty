#include "monty.h"

ostack_t *add_dnodeint(ostack_t **head, const int n)
{
	ostack_t *new = NULL;

	if (head)
	{
		new = malloc(sizeof(ostack_t));
		if (new)
		{
			new->n = n;
			new->prev = NULL;
			if (*head)
				(*head)->prev = new;
			new->next = *head;
			*head = new;
		}
	}

	return (new);
}

size_t print_dlistint(const ostack_t *h)
{
	size_t count = 0;

	while (h)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}
	return (count);
}

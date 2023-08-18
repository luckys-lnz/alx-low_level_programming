#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *insert_dnodeint_at_index - inserts a new node at a given position.
 *@h: double pointer to the beginning of the linked list.
 *@idx: index at which to insert the new node.
 *@n: data to pass into the new node
 *
 *Return: pointer to the new node, or NULL for failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *next, *cur_node;
	unsigned int i;

	if (h == NULL)
		return (NULL);
	if (idx != 0)
	{
		cur_node = *h;
		for (i = 0; i < idx - 1 && cur_node != NULL; i++)
			cur_node = cur_node->next;
		if (cur_node == NULL)
			return (NULL);
	}

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (idx == 0)
	{
		next = *h;
		*h = new;
		new->prev = NULL;
	}
	else
	{
		new->prev = cur_node;
		next = cur_node->next;
		cur_node->next = new;
	}

	new->next = next;
	if (new->next != NULL)
		new->next->prev = new;
	return (new);
}

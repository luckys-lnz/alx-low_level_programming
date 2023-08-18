#include "lists.h"
#include <stdlib.h>

/**
 *delete_dnodeint_at_index - deletes the node at index of dlistint_t
 *
 *@head: head of the list
 *@index: index of the node
 *Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *init_node;
	dlistint_t *after_node;
	unsigned int i;

	init_node = *head;

	if (init_node != NULL)
		while (init_node->prev != NULL)
			init_node = init_node->prev;

	i = 0;

	while (init_node != NULL)
	{
		if (i == index)
		{
			if (i == 0)
			{
			*head = init_node->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				after_node->next = init_node->next;

				if (init_node->next != NULL)
					init_node->next->prev = after_node;
			}

			free(init_node);
			return (1);
		}

		after_node = init_node;
		init_node = init_node->next;
		i++;
	}

	return (-1);
}

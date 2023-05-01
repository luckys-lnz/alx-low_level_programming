#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
  * insert_nodeint_at_index - ...
  * @head: ...
  * @idx: ...
  * @n: ...
  *
  * Return: ...
  */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *n_node, *iter;
	unsigned int add_count = 1;

	if (head)
	{
		n_node = malloc(sizeof(listint_t));
		if (n_node == NULL)
			return (NULL);

		n_node->n = n;
		if (idx > 0)
		{
			iter = *head;
			while (iter)
			{
				if (add_count == idx)
				{
					n_node->next = iter->next;
					iter->next = n_node;
					return (n_node);
				}
				iter = iter->next;
				add_count++;
			}
			if (idx > add_count)
				return (NULL);
		}
		else
		{
			n_node->next = *head;
			*head = n_node;
		}
		return (n_node);
	}
	return (NULL);
}

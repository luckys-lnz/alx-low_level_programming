#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index
 * of a linked list.
 * @head: head of a list.
 * @index: index of the list where the node is
 * deleted.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int a;
	listint_t *new;
	listint_t *next;

	new = *head;

	if (index != 0)
	{
		for (a = 0; a < index - 1 && new != NULL; a++)
		{
			new = new->next;
		}
	}

	if (new == NULL || (new->next == NULL && index != 0))
	{
		return (-1);
	}

	next = new->next;

	if (index != 0)
	{
		new->next = next->next;
		free(next);
	}
	else
	{
		free(prev);
		*head = next;
	}

	return (1);
}

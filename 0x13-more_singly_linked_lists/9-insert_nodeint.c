#include "lists.h"

/**
 * insert_nodeint_at_index - a function that inserts a new node at
 *                           a given position
 *
 * @head: pointer to the first node of the list
 * @idx: is the index of the list where the new node should be added
 * @n: element to add to the new node
 *
 * Return: NULL if anything fails or the address of the new node
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *n_node, *new;
	unsigned int index;

	new = *head; /*place first node at new*/
	n_node = malloc(sizeof(listint_t));
	if ((*head == NULL && idx != 0) || n_node == NULL)
		return (NULL);
	n_node->n = n;
	/* add our element to the new node*/
	for (index = 0; head != NULL && index < idx - 1; index++)
	{
		new = new->next;
		if (new == NULL)
			return (NULL);
	}
	if (idx == 0) /*if the index for new node is 0*/
	{
		n_node->next = *head;
		/*The new node will be placed as node 1*/
		*head = n_node;
	}
	else if (new->next)
	{
		n_node->next = new->next;
		new->next = n_node;
	}
	else /*if node position is not in the list*/
	{
		n_node->next = NULL;
		/*set next address location as NULL, indicates last node*/
		new->next = n_node;
	}

	return (n_node);
}

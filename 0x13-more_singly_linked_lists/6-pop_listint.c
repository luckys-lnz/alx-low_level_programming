#include "lists.h"

/**
 * pop_listint - deletes head of the node
 *
 * @head: pointer to the first node in the list
 *
 * Return: the head's node's data (n)
*/
int pop_listint(listint_t **head)
{
	int node_1;
	listint_t *cache, *n;

	/*if the list is empty return 0*/
	if (*head == NULL)
		return (0);

	/*set head address to cache*/
	cache = *head;
	/*get address of n node*/
	n = cache->n;
	/*get element of node_1*/
	node_1 = cache->n;

	/*free node_1*/
	free(cache);

	/*set a new node to a second node*/
	*head = n;

	/*return element of node_1*/
	return (node_1);
}

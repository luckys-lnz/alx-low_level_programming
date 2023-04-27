#include "lists.h"

/**
 * free_list - free single list link
 *
 * @head: pointer to the first node of the list
 *
 * Return: nothing
*/
void free_list(list_t *head)
{
	list_t *_new;

	/**
	 * while _new head is not NULL
	 * set head as the next node and
	 * free the _new node str then
	 * free _new node.
	*/
	while ((_new = head) != NULL)
	{
		head = head->next;
		free(_new->str);
		free(_new);
	}
}

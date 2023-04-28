#include "lists.h"

/**
 * free_listint2 - a function that frees the list and sets head to NULL
 *
 * @head: pointer to the first node
 *
 * Return: nothing
*/
void free_listint2(listint_t **head)
{
	listint_t *_new, *cache;

	if (head != NULL)
	{
		/*sets the head address to _new*/
		_new = *head;

		/*iterates through the list*/
		/*and sets the _new node to cache*/
		while ((cache = _new) != NULL)
		{
			/*sets next node to _new*/
			_new = _new->next;
			/*frees the cache, which is now the _new node*/
			free(cache);
		}

		*head = NULL;
	}
}

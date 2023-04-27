#include "lists.h"

/**
 * add_node_end - adds a node at the end of the linked list
 *
 * @head: pointer to the first node of the list
 * @str: string to add
 *
 * Return: NULL if it fails / starting addr of the list
*/

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *n_node, *cache;
	size_t str_len = 0;

	/*set strig length to 0 if its NULL*/
	if (str == NULL)
		str_len = 0;

	/*count length of string*/
	while (str[str_len] != '\0')
		str_len++;

	n_node = malloc(sizeof(list_t));
	if (n_node == NULL)
		return (NULL);

	n_node->str = strdup(str);
	n_node->len = str_len;
	n_node->next = NULL;

	/*copy our starting node pointer to cache*/
	cache = *head;

	/*if cache is NULL place  n_node at the beginning of the list*/
	/*else if its not null we place our n_node to cache->next hence*/
	/*adding our n_node at the end of the list*/
	if (cache == NULL)
		*head = n_node;
	else
	{
		/**
		 * we iterate pointer next addr if its not NULL our cache address
		 * points to the next address or the next node.
		*/
		while (cache->next != NULL)
			cache = cache->next;
		cache->next = n_node;
	}

	return (*head);
}

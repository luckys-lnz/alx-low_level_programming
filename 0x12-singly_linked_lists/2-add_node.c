#include "lists.h"

/**
 * add_node - adds a node at the beginning of the linked list
 *
 * @head: pointer to the first node of the list
 * @str: string to add to new node in the list
 *
 * Return: NULL if it fails / starting addr of the list
*/

list_t *add_node(list_t **head, const char *str)
{
	list_t *n_node;
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

	/**
	 * initialize the next addr of new_node
	 * to NULL if head is NULL, if it's not
	 * move the first node to the addr of new_node
	 * ->next hence adding new_node at the beginning
	 *  of the list
	*/
	if (*head == NULL)
		n_node->next = NULL;
	else
		n_node->next = *head;

	n_node->str = strdup(str);
	n_node->len = str_len;
	*head = n_node;

	return (*head);
}

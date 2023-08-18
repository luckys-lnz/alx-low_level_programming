#include "lists.h"

/**
 *sum_dlistint - sums up all of the data in dlistint_t linked list
 *@head: pointer to the start of the linked list
 *
 *Return: sum of data, 0 if list is empty
 */
int sum_dlistint(dlistint_t *head)
{

	int add = 0;

	while (head != NULL)
	{
		add += head->n;
		head = head->next;
	}

	return (add);
}

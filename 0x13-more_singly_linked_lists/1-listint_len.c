#include "lists.h"

/**
 * listint_len - a function that returns the number of element.
 *
 * @h: pointer to the first node
 *
 * Return: number of element
*/
size_t listint_len(const listint_t *h)
{
	size_t element = 1;

	/*return 0 as num of element where h is NULL*/
	if (h == NULL)
		return (0);

	while (h->next != NULL)
	{
		/*count num of element*/
		if (h->n != '\0')
			element++;

		/*go to next node*/
		h = h->next;
	}

	ret#include "lists.h"

/**
 * listint_len - a function that returns the num of element.
 *
 * @h: pointer to the first node
 *
 * Return: number of element
*/
size_t listint_len(const listint_t *h)
{
	size_t element = 1;

	/*return 0 as num of element where h is NULL*/
	if (h == NULL)
		return (0);

	while (h->next != NULL)
	{
		/*counts the num of element*/
		if (h->n != '\0')
			element++;

		/*go to next node*/
		h = h->next;
	}

	return (element);
}

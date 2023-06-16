#include "lists.h"

/**
 * dlistint_len - retrieves tye length of a doubky linked list
 *
 * @h: the head of the list
 *
 * Return: the length of the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t len = 0;
	const dlistint_t *head = h;

	if (head == NULL)
		return (len);

	while (head->prev != NULL)
		head = head->prev;

	while (head != NULL)
	{
		head = head->next;
		len++;
	}

	return (len);
}

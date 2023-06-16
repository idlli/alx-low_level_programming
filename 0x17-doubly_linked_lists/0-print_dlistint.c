#include "lists.h"

/**
 * print_dlistint - prints all elements in doubly linked list
 *
 * @h: the head of the list
 *
 * Return: the length of the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t len = 0;
	const dlistint_t *head = h;

	if (head == NULL)
		return (len);

	while (head->prev != NULL)
		head = head->prev;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		len++;
	}

	return (len);
}

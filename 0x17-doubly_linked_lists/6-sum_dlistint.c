#include "lists.h"

/**
 * sum_dlistint - sums all elements in a linked list
 *
 * @head: head of the list
 *
 * Return: the result of the sum of all elements
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (sum);

	while (head->prev != NULL)
		head = head->prev;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}

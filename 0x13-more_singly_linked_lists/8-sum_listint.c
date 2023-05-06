#include "lists.h"

/**
 * sum_listint - sum of all the data (n) of a listint_t linked list.
 * @head: pointer to the first node
 * Return: sum all the data
 */
 
int sum_listint(listint_t *head)
{
	if (head == NULL)
		return (0);

	int sum = head->n;
	sum += sum_listint(head->next);

	return (sum);
}

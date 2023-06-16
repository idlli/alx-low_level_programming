#include "lists.h"

/**
 * get_dnodeint_at_index - retrives a pointer node at specific inded
 *
 * @head: head of the list
 * @index: index to be retrived
 *
 * Return: node at @index, or NULL on failure
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (head == NULL)
		return (NULL);

	while (head->prev != NULL)
		head = head->prev;

	while (i++ < index)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
	}

	return (head);
}

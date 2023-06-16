#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes node at specific index from a list
 *
 * @head: the address of head of the list
 * @index: index of node to be deleted
 *
 * Return: 1 on success or -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	node = *head;

	while (node->prev != NULL)
		node = node->prev;

	while (i < index)
	{
		node = node->next;
		if (node == NULL)
			return (-1);
		i++;
	}

	if (*head == node)
		*head = node->next;

	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;

	free(node);

	return (1);
}

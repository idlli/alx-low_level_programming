#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node in the index
 * @head: a double pointer
 * @index: the index of node
 * Return: 1 if successful, -1 otherwise
 */
 
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	if (head == NULL || *head == NULL)
		return (-1);

	listint_t *current = *head, *prev = NULL;

	for (unsigned int i = 0; i < index; i++)
	{
		if (current == NULL)
			return (-1);
		prev = current;
		current = current->next;
	}

	if (prev == NULL)
		*head = current->next;
	else
		prev->next = current->next;

	free(current);
	return (1);
}
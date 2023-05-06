#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t linked list safely.
 * @head: double pointer to the start of the list
 * Return: the number of nodes in the list
 */
 
size_t free_listint_safe(listint_t **head)
{
	size_t count = 0;
	listint_t *current, *temp;

	if (head == NULL || *head == NULL)
		return (count);

	current = *head;
	while (current != NULL)
	{
		count++;
		if (current < current->next)
		{
			temp = current;
			current = current->next;
			free(temp);
		}
		else
		{
			free(current);
			*head = NULL;
			break;
		}
	}
	return (count);
}

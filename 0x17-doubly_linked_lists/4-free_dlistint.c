#include "lists.h"

/**
 * free_dlistint - frees a list from memory
 *
 * @head: head of the list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *next;

	if (head == NULL)
		return;

	while (head->prev != NULL)
		head = head->prev;

	do {
		next = head->next;
		free(head);
		head = next;
	} while (head != NULL);
}

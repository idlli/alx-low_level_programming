#include "lists.h"

/**
 * add_dnodeint - prepends a new elements at the end of a double linked list
 *
 * @head: the address of head of the list
 * @n: the new element value
 *
 * Return: a pointer to the new node, or NULL in case of failure
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *next = NULL;

	if (head == NULL)
		return (NULL);

	while ((*head) != NULL)
	{
		next = *head;
		head = &(*head)->prev;
	}

	*head = malloc(sizeof(dlistint_t));
	if (*head == NULL)
		return (NULL);

	(*head)->prev = NULL;
	(*head)->n = n;
	(*head)->next = next;

	return (*head);
}

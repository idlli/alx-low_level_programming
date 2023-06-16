#include "lists.h"

/**
 * add_dnodeint_end - appends a new elements at the end of a double linked list
 *
 * @head: the address of head of the list
 * @n: the new element value
 *
 * Return: a pointer to the new node, or NULL in case of failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t **h, *prev = NULL;

	if (head == NULL)
		return (NULL);
	h = head;

	while ((*head) != NULL)
	{
		prev = *head;
		head = &(*head)->next;
	}

	*head = malloc(sizeof(dlistint_t));
	if (*head == NULL)
		return (NULL);

	(*head)->prev = prev;
	(*head)->n = n;
	(*head)->next = NULL;

	head = h;

	return (*head);
}

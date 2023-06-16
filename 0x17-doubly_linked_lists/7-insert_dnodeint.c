#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a specefied index
 *
 * @h: the head of the list
 * @idx: position to insert at
 * @n: new element to be inserted
 *
 * Return: a pointer to the newly inserted node
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;
	dlistint_t **head = h, *new, *pre = NULL;

	if (h == NULL)
		return (NULL);

	if (*h != NULL)
	{
		while (i < idx)
		{
			if (*h == NULL)
				return (NULL);
			pre = *h;
			h = &(*h)->next;
			i++;
		}

		if (*h != NULL)
			(*h)->prev = NULL;
	}
	else if (idx != 0)
		return (NULL);

	new = add_dnodeint(h, n);

	if (pre)
		new->prev = pre, pre->next = new;
	else
		*head = new;

	return (new);
}

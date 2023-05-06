#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: Pointer to the first node of the list.
 * @index: Index of the node to return.
 * Return: Pointer to the node at the given index, or NULL if it doesn't exist.
 */
 
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int i;

    for (i = 0; head != NULL && i < index; i++)
        head = head->next;

    return (i == index) ? head : NULL;
}

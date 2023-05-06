#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - Add a node at the end of a linked list.
 * @head: Double pointer to the head of the linked list.
 * @n: Integer to add to the linked list.
 * Return: Pointer to the newly added node, or NULL if it fails.
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    listint_t *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;
    return (new_node);
}
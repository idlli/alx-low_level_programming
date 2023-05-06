#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - Remove the first node of a linked list and return its value.
 * @head: Double pointer to the head of the linked list.
 * Return: Value of the removed node.
 */
 
int pop_listint(listint_t **head)
{
    if (head == NULL || *head == NULL)
        return (0);

    listint_t *node_to_delete = *head;
    int value = node_to_delete->n;
    *head = node_to_delete->next;
    free(node_to_delete);

    return (value);
}

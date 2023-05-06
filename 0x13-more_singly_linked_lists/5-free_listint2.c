#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - Free a linked list and set the head to NULL.
 * @head: Double pointer to the head of the linked list.
 * Return: None.
 */
 
void free_listint2(listint_t **head)
{
    if (head == NULL || *head == NULL)
        return;

    listint_t *current = *head;
    while (current != NULL)
    {
        listint_t *next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}
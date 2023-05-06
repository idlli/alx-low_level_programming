#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - Free a linked list.
 * @head: Head of the linked list.
 * Return: None.
 */
 
void free_listint(listint_t *head)
{
    while (head != NULL)
    {
        listint_t *next = head->next;
        free(head);
        head = next;
    }
}
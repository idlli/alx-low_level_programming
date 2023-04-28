#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a linked list
 *
 * @head: A pointer to the first node of the list to free
 */
void free_list(list_t *head)
{
    if (head == NULL)
        return;

    free_list(head->next);
    free(head->str);
    free(head);
}

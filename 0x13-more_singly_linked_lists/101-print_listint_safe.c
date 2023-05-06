#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the start of the list
 * Return: the number of nodes in the list
 */
 
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow = head, *fast = head;
    size_t num = 0, flag = 0;

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        if (slow == fast->next || slow == fast->next->next)
        {
            flag = 1;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if (flag)
    {
        printf("-> [%p] %d\n", (void *)slow, slow->n);
        return (num);
    }
    while (head != NULL)
    {
        num++;
        printf("[%p] %d\n", (void *)head, head->n);
        head = head->next;
    }
    return (num);
}

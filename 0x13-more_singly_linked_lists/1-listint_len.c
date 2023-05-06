#include "lists.h"

/**
 * listint_len - Returns the number of elements in a linked listint_t list.
 * @h: Head pointer
 * Return: The number of elements
 */

size_t listint_len(const listint_t *h) {
    size_t count = 0;
    for (; h != NULL; count++, h = h->next);
    return (count);
}
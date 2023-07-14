#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - sets a new entry in a hash table
 *
 * @ht: the target hash table
 * @key: the key of the entry
 * @value: the value of the entry
 *
 * Return: 1 (success), 0 (failure)
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node, **head;
	unsigned long index;

	if (!ht || !key || !*key || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	head = &ht->array[index];
	node = *head;

	while (node != NULL && strcmp(key, node->key) != 0)
		node = node->next;

	if (node)
	{
		free(node->value);
		node->value = strdup(value);
		if (!node->value)
			return (0);
		return (1);
	}

	node = malloc(sizeof(hash_node_t));
	if (!node)
		return (0);
	node->key = strdup(key);
	node->value = strdup(value);
	if (!node->value)
	{
		free(node);
		return (0);
	}
	node->next = *head;
	*head = node;
	return (1);
}

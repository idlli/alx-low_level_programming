#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - retrieves a the value of a key of a hash table if exists
 *
 * @ht: the yarhet hash table
 * @key: the key of the item
 *
 * Return: the value or NULL if it doesn't exist
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long index;
	hash_node_t *node;

	if (!ht || !key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(key, node->key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

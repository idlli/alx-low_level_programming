#include "hash_tables.h"

/**
 * hash_table_delete - frees a hash table from memory
 *
 * @ht: the target hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long i;
	hash_node_t *node, *next;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			next = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = next;
		}
	}
	free(ht->array);
	free(ht);
	ht = NULL;
}

#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - prints all the key-value pairs in a hash table
 *
 * @ht: the target hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long i;
	int is_first_node = 1;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];

		while (node)
		{
			if (!is_first_node)
				printf(", ");

			printf("'%s': '%s'", node->key, node->value);
			node = node->next;
			is_first_node = 0;
		}
	}
	printf("}\n");
}

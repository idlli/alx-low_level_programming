#include "hash_tables.h"

/**
 * hash_table_create - creates a new hash table
 *
 * @size: size of the hash table
 *
 * Return: the newly created hash table's address
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new = malloc(sizeof(hash_table_t));
	unsigned int i;

	if (!new)
		return (NULL);

	new->size = size;
	new->array = malloc(size * sizeof(hash_node_t *));

	if (!new->array)
	{
		free(new);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		new->array[i] = NULL;

	return (new);
}

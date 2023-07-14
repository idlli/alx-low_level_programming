#include "hash_tables.h"

/**
 * key_index - takes a key and return an index
 *
 * @key: the key which index is to be determined
 * @size: the size of the hash table
 *
 * Return: a corresponding index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long hash = hash_djb2(key);

	return (hash % size);
}

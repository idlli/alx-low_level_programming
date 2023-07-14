#include "hash_tables.h"

/**
 * hash_djb2 - computes the hash valie of a string
 *
 * @str: the string to be hashed
 *
 * Return: the hash value of the string
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long hash = 5381;
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
		hash = ((hash << 5) + hash) + str[i];

	return (hash);
}

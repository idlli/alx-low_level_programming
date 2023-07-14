#include "hash_tables.h"
#include <stdio.h>
#include <string.h>

/**
 * shash_table_create - creates a new sorted hash table
 *
 * @size: size of the hash table
 *
 * Return: the newly created hash table's address
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new = malloc(sizeof(shash_table_t));
	unsigned int i;

	if (!new)
		return (NULL);

	new->size = size;
	new->shead = NULL;
	new->stail = NULL;
	new->array = malloc(size * sizeof(shash_node_t *));

	if (!new->array)
	{
		free(new);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		new->array[i] = NULL;

	return (new);
}

/**
 * shash_table_set - sets a new entry in a sorted hash table
 *
 * @ht: the target hash table
 * @key: the key of the entry
 * @value: the value of the entry
 *
 * Return: 1 (success), 0 (failure)
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node, **head;
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
		return (1);
	}

	node = malloc(sizeof(shash_node_t));
	if (!node)
		return (0);
	node->key = strdup(key);
	node->value = strdup(value);
	node->sprev = node->snext = NULL;
	if (ht->stail)
	{
	  node->sprev = ht->stail;
	  ht->stail->snext = node;
	}
	else
	  ht->shead = node;
	ht->stail = node;
	node->next = *head;
	*head = node;
	return (1);
}

/**
 * shash_table_get - retrieves a the value of a key of a hash table if exists
 *
 * @ht: the yarhet hash table
 * @key: the key of the item
 *
 * Return: the value or NULL if it doesn't exist
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long index;
	shash_node_t *node;

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

/**
 * shash_table_print - prints all the key-value pairs in a sorted hash table
 *
 * @ht: the target hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	const shash_node_t *node;

  if (!ht)
    return;

  node = ht->shead;

	if (node == NULL)
		return;

	printf("{");
	while (node)
	{
	  if (node != ht->shead)
	    printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints all the key-value pairs in hash table (rev)
 *
 * @ht: the target hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	const shash_node_t *node;

  if (!ht)
    return;

  node = ht->stail;

	if (node == NULL)
		return;

	printf("{");
	while (node)
	{
	  if (node != ht->stail)
	    printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - frees a sorted hash table from memory
 *
 * @ht: the target hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long i;
	shash_node_t *node, *next;

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

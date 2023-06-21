#include "main.h"

/**
 * _memcpy - Copies n amount of memory to another
 * @dest: the destination to copy into
 * @src: the source to vopy from
 * @n: the amount of bytes to copy
 * Return: The pointer to the destination
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}

#include "main.h"

/**
 * _memset - Fills memory with a constant byte
 * @s: the pointer to memory
 * @b: the byte to fill with
 * @n: the amount to fill
 * Return: The pointer to memory
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
		s[i++] = b;

	return (s);
}

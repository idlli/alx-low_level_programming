#include "main.h"

/**
 * _strncpy - Copies n amount of characters of one string to the other
 * @dest: the string to copy into
 * @src: the string to copy from
 * @n: the amount to copy
 * Return: The pointer to @dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i, src_drained;

	for (i = 0, src_drained = 0; i < n; i++)
	{
		if (src_drained)
			dest[i] = '\0';
		else
			dest[i] = src[i];

		if (!src_drained && src[i] == '\0')
			src_drained = 1;
	}

	return (dest);
}

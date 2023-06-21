#include "main.h"

/**
 * _strncat - Concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @n: the length to concatenate
 * Return: The pointer to @dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0, dest_len;

	while (dest[i] != '\0')
		i++;

	dest_len = i;

	while (src[i - dest_len] != '\0' && (i - dest_len) < n)
	{
		dest[i] = src[i - dest_len];
		i++;
	}
	dest[i] = '\0';


	return (dest);
}

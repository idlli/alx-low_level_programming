#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: the first string
 * @src: the second string
 * Return: The pointer to @dest
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, dest_len;

	while (dest[i] != '\0')
		i++;

	dest_len = i;

	while (src[i - dest_len] != '\0')
	{
		dest[i] = src[i - dest_len];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

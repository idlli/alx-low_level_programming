#include "main.h"

/**
 * _strcpy - Copies one string to the other
 * @dest: address of destination to copy into
 * @src: address of source to copy from
 * Return: The pointer to @dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = src[i];

	return (dest);
}

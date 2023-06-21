#include "main.h"

/**
 * _strlen - Determine the length of a string
 * @s: the address of the first character of a string
 * Return: The length of the string
 */

int _strlen(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
		len++;

	return (len);
}

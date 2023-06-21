#include "main.h"

/**
 * _strcmp - Compares two strings
 * @s1: the first string
 * @s2: the second string
 * Return:
 *	0 if the s1 is equal to s2
 *	a negative number if s1 is less than s2
 *	a positive number if s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

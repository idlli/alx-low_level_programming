#include "main.h"

/**
 * _strpbrk - Searches a string for any occurence of a set of chars
 * @s: the string to search
 * @accept: the group to search for
 * Return:
 *	A pointer to the matching char
 *	NULL elsewise
 */

char *_strpbrk(char *s, char *accept)
{
	int i;

	for (; *s; s++)
		for (i = 0; accept[i]; i++)
			if (*s == accept[i])
				return (s);
	return (NULL);
}

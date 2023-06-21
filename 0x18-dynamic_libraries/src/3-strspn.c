#include "main.h"

/**
 * _strspn - Get length of substring that consists of specific letters
 * @s: the string to check
 * @accept: the acceptable group of letters
 * Return: the length of the substring
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, k;

	for (i = 0; s[i]; i++)
	{
		for (j = 0, k = 0; accept[j]; j++)
			if (s[i] == accept[j])
				k = 1;
		if (!k)
			break;
	}

	return (i);
}

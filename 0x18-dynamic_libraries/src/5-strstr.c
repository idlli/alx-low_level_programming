#include "main.h"

/**
 * _strstr - Searches for a substring in a string
 * @haystack: the string to search
 * @needle: the substring to search for
 * Return:
 *	A pointer to the first occurence of the substring
 *	NULL elsewise
 */

char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (; *haystack; haystack++)
	{
		for (i = 0, j = 0; needle[i]; i++)
			if (haystack[i] != needle[i])
				j = 1;
		if (!j)
			return (haystack);
	}

	return (NULL);
}

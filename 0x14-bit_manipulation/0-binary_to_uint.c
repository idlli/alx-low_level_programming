#include "main.h"

/**
 * binary_to_uint - converts a binary to an unsigned int.
 * @b: pointer to a string of 0 and 1 chars
 * Return: the converted number, or 0 if b is NULL or has invalid characters
 */
 
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (!b)
		return (0);

	for (; *b != '\0'; b++)
	{
		if (*b != '0' && *b != '1')
			return (0);

		result = result << 1;
		if (*b == '1')
			result += 1;
	}

	return (result);
}

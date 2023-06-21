#include "main.h"

/**
 * _isupper - Checks whether a character is uppercase
 * @c: the character to check
 * Return:
 * 1 if the letter is uppercase
 * 0 elsewise
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);

	return (0);
}

#include "main.h"

/**
 * _isdigit - Checks whether a character is a digit
 * @c: the character to check
 * Return:
 * 1 if the character is a digit
 * 0 elsewise
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

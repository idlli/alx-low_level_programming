#include "main.h"

/**
 * _isalpha - checks whether a char is alphabetic
 * @c: the character to check
 * Return:
 * 1 if the char is alphabetic
 * 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

#include "main.h"

/**
 * _abs - computes the ablsolute value of an integer
 * @n: the integer to compute its absolute value
 * Return: the absolute value of n
 */
int _abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

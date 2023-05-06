#include "main.h"

/**
 * get_bit - returns the value of the bit at a given index
 * @n: the number to check bits from
 * @index: the position of the bit to check, starting from 0 for the least significant bit
 * Return: 1 or 0 if the bit is set or unset, or -1 if index is out of range
 */
 
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);

	return ((n >> index) & 1);
}

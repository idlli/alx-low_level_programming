#include "main.h"

/**
 * _puts - Prints a string of chars to stdout
 * @str: the address to the first char of the string
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}

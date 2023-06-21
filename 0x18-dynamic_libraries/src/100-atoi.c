#include "main.h"

/**
 * _atoi - Converts from string to integer
 * @s: the string to convert
 * Return: 0 if the conversion is successful, 1 elsewise
 */

int _atoi(char *s)
{
	int started = 0,
	    result = 1;

	while (*s != '\0')
	{

		if (*s == '-')
			result *= -1;

		if (*s >= '0' && *s <= '9')
		{
			if (started)
			{
				result *= 10;
				result += (*s - '0') * (result < 0 ? -1 : 1);
			}
			else
			{
				result *= *s - '0';
				started = 1;
			}
		}
		else if (started)
		{
			break;
		}

		s++;
	}

	if (started)
		return (result);
	else
		return (0);
}

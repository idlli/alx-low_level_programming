#include <stdlib.h>

/**
 * f4 - helper function 4
 *
 * @arg1: username string
 * @arg2: username length
 *
 * Return: an index below 64
 */
unsigned long f4(char *arg1, int arg2)
{
	int temp = *arg1, i;

	for (i = 0; i < arg2; i = (i + 1))
	{
		if (arg1[i] > temp)
		{
			temp = arg1[i];
		}
	}
	srand((temp ^ 0xe));
	return (rand() & 0x3f);
}

/**
 * f5 - helper function 5
 *
 * @arg1: username string
 * @arg2: username length
 *
 * Return: an index below 64
 */
unsigned long f5(char *arg1, int arg2)
{
	int temp = 0, i, res;

	for (i = 0; i < arg2; i = (i + 1))
	{
		temp = (temp + (*(arg1 + i) * *(arg1 + i)));
	}
	res = (temp ^ 0xef);
	return (res & 0x3f);
}

/**
 * f6 - helper function 6
 *
 * @arg1: first char of username string
 *
 * Return: an index below 64
 */
unsigned long f6(char arg1)
{
	int temp = 0, i, rax_3;

	for (i = 0; arg1 > i; i = (i + 1))
	{
		temp = rand();
	}
	rax_3 = (temp ^ 0xe5);
	return (rax_3 & 0x3f);
}


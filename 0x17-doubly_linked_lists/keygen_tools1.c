/**
 * f1 - helper function 1
 *
 * @arg1: username length
 *
 * Return: an index below 64
 */
unsigned long f1(int arg1)
{
	return ((arg1 ^ 0x3b) & 0x3f);
}

/**
 * f2 - helper function 2
 *
 * @arg1: username string
 * @arg2: username length
 *
 * Return: an index below 64
 */
unsigned long f2(char *arg1, int arg2)
{
	int temp = 0, i;

	for (i = 0; i < arg2; i = (i + 1))
	{
		temp = (temp + *(arg1 + i));
	}
	return ((temp ^ 0x4f) & 0x3f);
}

/**
 * f3 - helper function 3
 *
 * @arg1: username string
 * @arg2: username length
 *
 * Return: an index below 64
 */
unsigned long f3(char *arg1, int arg2)
{
	int temp = 1, i;

	for (i = 0; i < arg2; i = (i + 1))
	{
		temp = (*(arg1 + i) * temp);
	}
	return ((temp ^ 0x55) & 0x3f);
}


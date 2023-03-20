#include <stdio.h>
/**
 * main - main block
 * Print alphabet in Lowercase and then uppercase
 * Return: Always 0
 */
int main(void)
{
	char b = 'a';

	while (b <= 'z')
	{
		putchar(b);
		b++;
	}
	b = 'A';
	while (b <= 'Z')
	{
		putchar(b);
		b++;
	}
	putchar('\n');
	return (0);
}

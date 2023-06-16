#include <stdio.h>
#include <stdlib.h>
#include "keygen_tools1.c"
#include "keygen_tools2.c"

/**
 * _strlen - retrieves the length of a string
 *
 * @str: the string
 *
 * Return: length of @str
 */
unsigned int _strlen(const char *str)
{
	unsigned int len = 0;

	if (!str)
		return (len);

	while (str[len])
		len++;
	return (len);
}

/**
 * main - entry point
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: always EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
	char *m = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char pwd[7];
	char *user = argv[1];
	int len = _strlen(user);

	(void)argc;
	pwd[0] = m[f1(len)];
	pwd[1] = m[f2(user, len)];
	pwd[2] = m[f3(user, len)];
	pwd[3] = m[f4(user, len)];
	pwd[4] = m[f5(user, len)];
	pwd[5] = m[f6(*user)];

	printf("%s", pwd);
	return (EXIT_SUCCESS);
}

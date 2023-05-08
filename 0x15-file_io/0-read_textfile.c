#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: pointer to the name of the file.
 * @letters: The number of letters the function should read and print.
 * Return: If the function fails or filename is NULL - 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t _op, _re, _wr;
	char *buffer;

	buffer = malloc(sizeof(char) * letters);

	if (!(buffer))
	{
		free(buffer);
		return (0);
	}
	if (!(filename))
	{
		return (0);
	}

	_op = open(filename, O_RDONLY);
	_re = read(_op, buffer, letters);
	_wr = write(STDOUT_FILENO, buffer, _re);

	if (_op == -1 || _re == -1 || _wr == -1 || !(_wr == _re))
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(_op);

	return (_wr);
}

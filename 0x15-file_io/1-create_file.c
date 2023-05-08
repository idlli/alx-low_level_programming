#include "main.h"
/**
 * create_file - creates an array of chars, and initializes
 * @text_content: is a NULL terminated string to write to the file
 * @filename: is the name of the file
 * Return: 1 on success, -1 on failure (file can not be created, file can not be written, write “fails”, etc…)
 */
int create_file(const char *filename, char *text_content)
{
	int _op, _wr, _leng = 0;

	if (!(filename))
	{
		return (-1);
	}

	_op = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (_op == -1)
	{
		return (-1);
	}

	if (text_content)
	{
		while (text_content[_leng])
		{
			_leng++;
		}
		_wr = write(_op, text_content, _leng);
		if (_wr == -1)
		{
			return (-1);
		}
	}

	if (_op == -1 || _wr == -1)
		return (-1);

	close(_op);
	return (1);
}

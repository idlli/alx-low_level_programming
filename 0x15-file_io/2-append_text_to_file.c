#include "main.h"
/**
 * append_text_to_file - appends a text at the end of a file.
 * @filename: name of the file
 * @text_content: NULL terminated string to add the end of the file
 * Return: 1 if success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t _leng;
	int _file;

	if (!(filename))
		return (-1);
	_file = open(filename, O_WRONLY | O_APPEND);
	if (_file == -1)
		return (-1);
	if (text_content) {
		_leng = write(_file, text_content, _strlen(text_content));
		if (_leng == -1)
		{
			close(_file);
			return (-1);
		}
	}

	close(_file);
	return (1);
}

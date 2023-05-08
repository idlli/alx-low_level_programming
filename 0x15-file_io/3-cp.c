#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
* main - copy info from file_from to file_to.
* @argc: number of arguments
* @argv: array of arguments
* Return: Always 0.
*/

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: cp file_from file_to\n");
        return 1;
		exit(97);
    }

    int file_from = open(argv[1], O_RDONLY);
    if (file_from == -1) {
        fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
        return 1;
    }

    int file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (file_to == -1) {
        fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
        close(file_from);
		exit(99);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;
    while ((bytes_read = read(file_from, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(file_to, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
            close(file_from);
            close(file_to);
			exit(98);
            return 1;
        }
    }

    if (bytes_read == -1) {
        fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
        close(file_from);
        close(file_to);
		exit(99);
        return 1;
    }

    if (close(file_from) == -1) {
        fprintf(stderr, "Error: Can't close fd %s\n", argv[1]);
        close(file_to);
		exit(100);
        return 1;
    }

    if (close(file_to) == -1) {
        fprintf(stderr, "Error: Can't close fd %s\n", argv[2]);
		exit(100);
        return 1;
    }

    return 0;
}

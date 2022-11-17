#include "shell.h"

/**
 * _read_buffer - Read from stdin
 *
 * Return: string
 */


char *_read_buffer(void)
{
	char *buffer = NULL;
	size_t n;
	int nread = 0;

	nread = getline(&buffer, &n, stdin);
	if (nread == -1)
		exit(EXIT_FAILURE);

	/* remove \n from buffer */
	buffer[nread - 1] = '\0';
	return (buffer);
}


#include"monty.h"
/**
 * _getline - Read a line from a file stream
 * @lineptr: A pointer to the buffer where the line will be stored
 * @n: A pointer to the size of the buffer
 * @stream: The file stream to read from
 *
 * Return: The number of characters read or -1 on failure
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t i = 0;
	int c;
	char *temp;

	temp = realloc(*lineptr, *n);

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			perror("_getline: malloc failed");
			exit(EXIT_FAILURE);
		}
	}
	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		(*lineptr)[i++] = (char)c;
		if (i == *n - 1)
		{
			*n *= 2;

			if (temp == NULL)
			{
				perror("_getline: realloc failed");
				free(*lineptr);
				exit(EXIT_FAILURE);
			}
			*lineptr = temp;
		}
	}
	(*lineptr)[i] = '\0';
	return ((c == EOF && i == 0) ? -1 : (ssize_t)i);
}

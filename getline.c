#include "simple_shell.h"
/**
 * custom_getline - Read a line from strd input and store it in a dynamically allocated buffer.
 * @lineptr: A pointer to the buffer where the line will be stored.
 * @n: A pointer to the size of the buffer.
 *
 * Return: The number of characters read, or -1 on failure or end of file.
 */
ssize_t custom_getline(char **lineptr, size_t *n)
{
	size_t pos = 0;
	int c;

	if (*lineptr == NULL)
	{
		allocate_buffer(lineptr, n);
	}
	while (1)
	{
		c = getchar();
		if (c == EOF)
		{
			if (pos == 0)
			{
				free(*lineptr);
				*lineptr = NULL;
				return (-1);
			}
			(*lineptr)[pos] = '\0';
			return (pos);
		}
		if (c == '\n')
		{
			(*lineptr)[pos] = '\0';
			return (pos);
		}
		(*lineptr)[pos] = c;
		pos++;
		if (pos >= *n - 1)
		{
			*n *= 2;
			*lineptr = realloc(*lineptr, *n);
			if (*lineptr == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (-1);
}





/**
 * allocate_buffer - Allocate an initial buffer for custom_getline.
 * @lineptr: A pointer to the buffer where the line will be stored.
 * @n: A pointer to the size of the buffer.
 */

void allocate_buffer(char **lineptr, size_t *n)
{
	*lineptr = (char *)malloc(MAX_INPUT_SIZE);
	if (*lineptr == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	*n = MAX_INPUT_SIZE;
}





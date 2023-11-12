#include "simple_shell.h"

ssize_t custom_getline(char **lineptr, size_t *n)
{
	size_t pos = 0;
	int c;

	if (*lineptr == NULL)
	{
		*lineptr = (char *)malloc(MAX_INPUT_SIZE);
		if (*lineptr == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		*n = MAX_INPUT_SIZE;
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

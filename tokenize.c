
#include "simple_shell.h"


/**
 * custom_tokenize - Custom function to tokenize input.
 * @input: The input string to be tokenized.
 * @args: An array to store the tokenized arguments.
 * @arg_count: A pointer to an integer to store the number of arguments.
 */
void custom_tokenize(char *input, char *args[], int *arg_count)
{
	char *start = input;
	char *end = input;
	
	while (*end != '\0' && *arg_count < MAX_ARGS - 1)
	{
		while (*end != ' ' && *end != '\0')
		{
			end++;
		}
		if (*start != '\0')
		{
			args[(*arg_count)++] = strndup(start, end - start);
		}

		if (*end == ' ')
		{
			start = ++end;
		}
	}
	args[*arg_count] = NULL;
}

#include "simple_shell.h"
/**
 * main - Entry point for thids simple shell program.
 * Return: Always 0. for both succes ans=d fail
 */



int main(void)
{
	/*char input[MAX_INPUT_SIZE];*/
	char *input = NULL;
	size_t input_size = 0;
	char *custom_path = "/bin";
	char *path = getenv("PATH");
	char new_path[MAX_INPUT_SIZE];
	ssize_t chars_read;
	if (path == NULL)
	{
		snprintf(new_path, sizeof(new_path), "PATH=%s", custom_path);
	}
	else
	{
		snprintf(new_path, sizeof(new_path), "PATH=%s:%s", custom_path, path);
	}
	putenv(new_path);
	while (1)
	{
		display_prompt();
		chars_read = custom_getline(&input, &input_size);
		if (chars_read == -1)
		{
			printf("\n");
			free(input);
			exit(EXIT_FAILURE);
		}
		if (chars_read == 0)
		{
			continue;
		}
		if (strcmp(input, "exit") == 0)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		execute_command_with_args(input);

	}
	free(input);
	return (0);
}


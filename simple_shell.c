#include "simple_shell.h"
/**
 * main - Entry point for thids simple shell program.
 * Return: Always 0. for both succes ans=d fail
 */



int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *custom_path = "/bin";
	char *path = getenv("PATH");
	char new_path[MAX_INPUT_SIZE];

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
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		if (strcmp(input, "exit") == 0)
		{
			exit(0);
			break;
			return (-1);
		}
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			exit(0);
		}

		/*execute_command(input);*/
		execute_command_with_args(input);

	}
	return (0);
}


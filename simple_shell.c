#include "simple_shell.h"
/**
 * main - Entry point for thids simple shell program.
 * Return: Always 0. for both succes ans=d fail
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];


	while (1)
	{
		display_prompt();
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		input[strcspn(input, "\n")] = '\0';
		execute_command(input);
	}

	return (0);
}

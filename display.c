#include "simple_shell.h"

/**
 * display_prompt - this is the function that displays the prompt to the user
 * Return: void
 */

void display_prompt(void)
{
	printf("$ ");
}


/**
 * execute_command - Execute a shell command.
 * @command: The command to be executed.
 */

void execute_command(char *command)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("Fork failed");
	}
	else if (pid == 0)
	{
		char *args[2];


		args[0] = command;
		args[1] = NULL;

		if (execvp(command, args) == -1)
		{
			fprintf(stderr, "./hsh: No such file or directory\n");
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);

	}
}

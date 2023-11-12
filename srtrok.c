#include "simple_shell.h"
/**
 * execute_command - execute the input command
 * @command: pointer to a string
 * Return: success
 */
int execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (1);
	}

	if (pid == 0)
	{
		if (execlp(command, command, NULL) == -1)
		{
			perror("execlp");
			return (1);
		}
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
	}

	return (0);
}

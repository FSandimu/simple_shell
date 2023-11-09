


#include "simple_shell.h"
/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void)
{
	printf("$ ");
}

/**
 * execute_command_with_args - Execute a command with arguments.
 * @command: The command with arguments.
 */
void execute_command_with_args(char *command)
{
	char *args[MAX_ARGS];
	int arg_count = 0;
	char *token = strtok(command, " ");
	char *full_path;

	while (token != NULL)
	{
		args[arg_count] = token;
		token = strtok(NULL, " ");
		arg_count++;
	}
	args[arg_count] = NULL;
	if (args[0][0] == '/' || args[0][0] == '.')
	{
		full_path = args[0];
	}
	else
	{
		char *path = getenv("PATH");
		char *path_token = strtok(path, ":");

		while (path_token != NULL)
		{
			char full_path_candidate[MAX_INPUT_SIZE];

			snprintf(full_path_candidate,
					sizeof(full_path_candidate), "%s/%s", path_token, args[0]);
			if (access(full_path_candidate, X_OK) == 0)
			{
				full_path = full_path_candidate;
				break;
			}
			path_token = strtok(NULL, ":");
		}
	}
	if (full_path != NULL)
		execute_command_with_path(full_path, args);
	else
		fprintf(stderr, "%s: command not found\n", args[0]);
}

/**
 * execute_command_with_path - Execute a command with the specified path.
 * @full_path: The full path to the command.
 * @args: An array of arguments, including the command.
 */

void execute_command_with_path(char *full_path, char *args[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
	}
	else if (pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror("Exec failed");
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			WEXITSTATUS(status);
		}
	}
}


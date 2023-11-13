


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
	/*char *full_path = NULL;*/
	char *full_path = malloc(MAX_INPUT_SIZE);


	custom_tokenize(command, args, &arg_count);
	if (arg_count > 0 && strcmp(args[0], "exit") == 0)
		execute_exit(arg_count, args);
	else if (arg_count > 0 && strcmp(args[0], "setenv") == 0)
		execute_setenv(args);
	else if (arg_count > 0 && strcmp(args[0], "unsetenv") == 0)
		execute_unsetenv(args);
	else if (arg_count > 0 && strcmp(args[0], "cd") == 0)
		execute_cd(args);
	if (args[0][0] == '/' || args[0][0] == '.')
		/*full_path = args[0];*/
		strncpy(full_path, args[0], MAX_INPUT_SIZE);
	else
	{
		find_full_paths(args, full_path);
	}
	if (full_path != NULL)
		execute_command_with_path(full_path, args);
	else
		fprintf(stderr, "%s: command not found\n", args[0]);
}

/**
 * find_full_paths - Search for the full path of a command in directories
 * @args: An array of command arguments, where args[0] is the command to find.
 * @full_path: A buffer to store the full path of the command if found.
 *
 * Return: No explicit return value.
 */

void find_full_paths(char *args[], char *full_path)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *path_token = path_copy;

	while (path_token != NULL)
	{
		char full_path_candidate[MAX_INPUT_SIZE];
		char *token_end = strchr(path_token, ':');

		if (token_end != NULL)
			*token_end = '\0';
		snprintf(full_path_candidate, sizeof(full_path_candidate),
				"%s/%s", path_token, args[0]);
		if (access(full_path_candidate, X_OK) == 0)
		{
			strcpy(full_path, full_path_candidate);
			break;
		}
		if (token_end == NULL)
			break;
		path_token = token_end + 1;
	}
	free(path_copy);
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

	if (full_path == NULL)
	{
		fprintf(stderr, "Command not found\n");
		exit(EXIT_FAILURE);
	}

	printf("Executing command: %s\n", full_path);

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


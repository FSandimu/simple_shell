#include "simple_shell.h"
/**
 * display_prompt - this is the function that displays the prompt to the user
 * Return: void
 */
void display_prompt()
{
	printf("$ ");
}
/**
 * execute_command_with_args - its the fuction i implement to handle cmd args
 * @command: the cmd to be handled
 * basically this is taskn 2 .
 * note : environ variable is defined in the header file
 *
 * basically this impliments task index o2
 */



void execute_command_with_args(char *command)
{
	char *args[MAX_ARGS];
	char *full_path;
	int arg_count = 0;
	char *token = strtok(command, " ");
	
	while (token != NULL)
	{
		args[arg_count] = token;
		token = strtok(NULL, " ");
		arg_count++;
	}
	args[arg_count] = NULL;
	full_path = find_command(args[0]);
	if (full_path != NULL)
	{
		args[0] = full_path;
		if (execve(full_path, args, environ) == -1)
		{
			perror("Exec failed");
			exit(1);
		}
		free(full_path);
	}
	else
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		exit(1);
	}
}
/**
 * execute_command - Execute a shell command.
 * @command: The command to be executed.i
 *
 */


void execute_command(char *command)
{
	/*
	 * char *full_command = find_command(command);

	pid_t pid;

	if (full_command == NULL)
	{
		fprintf(stderr, "%s: command not found\n", command);
		return;
	}* the above code is hashed since it breaks the execution implemets task 3 (ii)
	* TODO implement it and also do betty on this file
	*/

	pid_t pid = fork();
	
	if (pid == -1)
	{
		perror("Fork failed");
	}
	else if (pid == 0)
	{
		execute_command_with_args(command);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			WEXITSTATUS(status);
			
		}
	}
}

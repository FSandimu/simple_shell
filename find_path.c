#include "simple_shell.h"
/**
 *  find_command - the function used to find the path
 * this file contains  the func that is used to find path of a command (no3.
 * find_command - the function used to find the path
 * @command: the command as an arg
 * Return: the full path as a dynamically alocated string or Null If fails
 */



char *find_command(char *command)
{
	char *path = getenv("PATH");
	
	
	char *token = strtok(path, ":");
	
	while (token != NULL)
	{
		char full_path[MAX_INPUT_SIZE];
		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			return strdup(full_path);
		}
		token = strtok(NULL, ":");
	}
	return NULL;
}

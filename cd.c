#include "simple_shell.h"



/**
 * execute_cd - Change the current working directory and update env variabl
 * @args: An array of command arguments, where args[1] is the target directory.
 *
 * Return: No explicit return value.
 */
void execute_cd(char *args[])
{
	char current_dir[MAX_INPUT_SIZE];
	char new_dir[MAX_INPUT_SIZE];
	char *target_dir;
	char *cwd;

	if (args[1] == NULL || strcmp(args[1], "~") == 0)
	{
		target_dir = getenv("HOME");
	}
	else if (strcmp(args[1], "-") == 0)
	{
		target_dir = getenv("OLDPWD");
	}
	else
	{
		target_dir = args[1];
	}
	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("getcwd");
		return;
	}
	if (chdir(target_dir) != 0)
	{
		perror("cd");
	}
	else
	{
		setenv("OLDPWD", current_dir, 1);
		cwd = getcwd(new_dir, sizeof(new_dir));
		if (cwd == NULL)
		{
			perror("getcwd");
			return;
		}
		setenv("PWD", cwd, 1);
	}
}



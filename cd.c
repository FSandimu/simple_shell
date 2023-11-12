#include "simple_shell.h"

/**
 *
 *
 *
 */
void cd(char *path)
{
	if (chdir(path) != 0)
	{
		perror("cd");
	}
	else
	{
		char new_pwd[1024];
		getcwd(new_pwd, sizeof(new_pwd));
		setenv("PWD", new_pwd, 1);
	}
}
int main(void)
{
	char *input = "cd /path/to/directory";
	char *cmd = strtok(input, " ");
	char *path = strtok(NULL, " ");

	if (strcmp(cmd, "cd") == 0)
	{
		if (path == NULL)
		{
			path = getenv("HOME");
		}
		cd(path);
	}

	return (0);
	}

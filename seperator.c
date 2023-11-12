#include "simple_simple.h"

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

void exec_cmd(char *cmd)
{
	if (strncmp(cmd, "cd", 2) == 0)
	{
		char *path = strtok(NULL, " ");
		if (path == NULL)
		{
			path = getenv("HOME");
		}
		cd(path);
	}
	else
	{
		system(cmd);
	}
}

int main(void)
{
	//assume you have already implemented a command parser and other utilities
	char *input = "cd /path/to/directory; ls";
	char *cmd = strtok(input, ";");

	while (cmd != NULL)
	{
		exec_cmd(cmd);
		cmd = strtok(NULL, ";");
	}

	return (0);
}

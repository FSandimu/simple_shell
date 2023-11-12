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
		pid_t pid = fork();
		if (pid == 0)
		{
			// Child process
			if (execl("/bin/sh", "sh", "-c", cmd, (char *)0) < 0)
			{
				perror("execl");
			}
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
		// Failed to fork
			perror("fork");
		}
		else
		{
			 // Parent process
			int status;
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
			}
		}
	}
}

int main(void)
{
	 // assume you have already implemented a command parser and other utilities
	char *input = "cd /path/to/directory && ls || echo 'Error changing directory'";
	char *cmd = strtok(input, "&&||;");

	while (cmd != NULL)
	{
		exec_cmd(cmd);
		cmd = strtok(NULL, "&&||;");
	}

	return (0);
}

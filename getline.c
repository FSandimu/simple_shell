#include "simple_shell.h"

/**
 * getline - prints a line
 * @buf: line to be printed
 * Return: void
 */
void getline(char *buf)
{
	int i = 0;
	while (1)
	{
		char c = getchar();
		if (c == '\n' || c == EOF)
		{
			buf[i] = '\0';
			break;
		}
	buf[i++] = c;
	}
}

int main(void)
{
	char input[MAX_LENGTH];

	while (1)
	{
		printf("$ ");
		getline(input);

		if (strncmp(input, "exit", 4) == 0)
		{
			break;
		}
		pid_t pid = fork();

		if (pid == 0)
		{
			char *argv[] = {"sh", "-c", input, NULL};
			if (execv("/bin/sh", argv) == -1)
			{
				perror("execv");
			}
			exit(0);
		}
		else if (pid < 0)
		{
			perror("fork");
		}
		else
		{
			int status;
			waitpid(pid, &status, 0);
		}
	}
	return 0;
}


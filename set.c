#include "simple_shell.h"

/**
 *
 *
 *
 */

int execute_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		printf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (1);
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		perror("setenv");
		return (1);
	}

	return (0);
}

int execute_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		printf(stderr, "Usage: unsetenv VARIABLE\n");
		return (1);
	}

	if (unsetenv(args[1]) == -1)
	{
		perror("unsetenv");
		return (1);
	}

	return (0);
}

/**
 * int main(void)
{
	char *args[] = {"setenv", "GREETING", "Hello, World!"};
	execute_setenv(args);

	args[0] = "unsetenv";
	args[1] = "GREETING";
	execute_unsetenv(args);

	return (0);
}*/

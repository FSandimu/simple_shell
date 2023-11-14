#include "simple_shell.h"



/**
 * execute_setenv - Set environment variable.
 * @args: Array of arguments containing variable name and value.
 */
void execute_setenv(char *args[])
{
	int success;

	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return;
	}
	success = setenv(args[1], args[2], 1);
	if (success == 0)
	{
		printf("Variable %s set to %s\n", args[1], args[2]);
	}
	else
	{
		perror("setenv");
	}
}

/**
 * execute_unsetenv - Unset environment variable.
 * @args: Array of arguments containing variable name.
 */
void execute_unsetenv(char *args[])
{
	if (args[0] != NULL && args[1] != NULL && args[2]
			== NULL && args[1][0] != '\0')
	{
		if (unsetenv(args[1]) == -1)
		{
			perror("unsetenv");
		}
		else
		{
			printf("Variable %s unset\n", args[1]);
		}
	}
	else
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
	}
}

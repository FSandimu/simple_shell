#include "simple_shell.h"
/**
 * execute_exit - Handles the exit built-in command.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Description:
 * - If an arg is provided, convert it to an int to use it as the exit status.
 * - If no argument is provided, use the default exit status (EXIT_SUCCESS).
 */
void execute_exit(int argc, char *argv[])
{
	int status;

	if (argc > 1)
	{
		status = atoi(argv[1]);
		exit(status);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}

	printf("$ exit %d\n", status);
	exit(status);
}

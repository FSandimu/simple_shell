#include "simple_shell.h"
/**
 * exit_builtin - exits the shell
 * Return: zero
 */
/*void exit_builtin(void)
{
	exit(0);
}

int main(void)
{
    char input[MAX_LENGTH];

    while (1)
    {
	printf("$ ");
        fgets(input, MAX_LENGTH, stdin);

	if (strncmp(input, "exit", 4) == 0)
	{
		exit_builtin();
        }
    }

	return (0);
}*/
void execute_exit(int argc, char *argv[])
{
	if (argc > 1)
	{
		int status = atoi(argv[1]);
		exit(status);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}

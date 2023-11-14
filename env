#include "simple_shell.h"

/*
 * env_builtin - prints current environment
 * Return: void
 */
void env_builtin(void)
{
	char **environ;
	char *const *envp = (char * const *)environ;

	while (*envp != NULL)
	{
		printf("%s\n", *envp);
		envp++;
	}
}

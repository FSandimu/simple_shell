#include "simple_shell.h"

/*
 * env_builtin - prints the current environment
 *
 * Return: void
 */
void env_builtin()
{
    extern char **environ;
    char * const * envp = (char * const *)environ;

    while (*envp != NULL)
    {
        printf("%s\n", *envp);
        envp++;
    }
}

/*int main(void)
{
    char input[MAX_LENGTH];

    while (1) {
        printf("$ ");
        fgets(input, MAX_LENGTH, stdin);

        if (strncmp(input, "env", 3) == 0) {
            env_builtin();
        }
    }

    return 0;
}*/

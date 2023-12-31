#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 32
extern char **environ;

/**
 * execute_command_with_args - Executes a command with arguments.
 *
 * @command: The command to be executed.
 */
void execute_command_with_args(char *command);
ssize_t custom_getline(char **lineptr, size_t *n);
void execute_unsetenv(char *args[]);
void execute_setenv(char *args[]);
void allocate_buffer(char **lineptr, size_t *n);
void execute_exit(int argc, char *argv[]);
void custom_tokenize(char *input, char *args[], int *arg_count);
void execute_cd(char *args[]);
void find_full_paths(char *args[], char *full_path);
void display_prompt(void);
void execute_command_with_path(char *full_path, char *args[]);
void executeEnv(char *environ[]);

#endif

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
 * the above variable is the environment variable which is from unistd,h*/
void execute_command_with_args(char *command);

void display_prompt(void);
void execute_command_with_path(char *full_path, char *args[]);
void executeEnv(char *environ[]);

#endif

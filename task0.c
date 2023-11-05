#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * main - Entry point to the program
 * Return: 0
 */
int get_pid(void)
{
	pid_t parent_pid;
	pid_t child_pid;

	child_pid = getpid();
	parent_pid = getppid();
	printf("This is the pid: %u\n", child_pid);
	printf("This is the ppid: %u\n", parent_pid);

	return (0);
}

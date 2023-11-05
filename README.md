Commands to use:
Here are the summaries of the requested functions:

access (man 2 access): Checks the user’s permissions for a file12.
chdir (man 2 chdir): Changes the current working directory of the calling process to the directory specified in path34.
close (man 2 close): Closes a file descriptor, so that it no longer refers to any file and may be reused56.
closedir (man 3 closedir): Closes the directory stream associated with dirp. A successful call to closedir also closes the underlying file descriptor associated with dirp78.
execve (man 2 execve): Executes the program referred to by pathname96.
exit (man 3 exit): Terminates the calling process “immediately”. Any open file descriptors belonging to the process are closed10.
_exit (man 2 _exit): Terminates the calling process “immediately”. Any open file descriptors belonging to the process are closed11.
fflush (man 3 fflush): For output streams, forces a write of all user-space buffered data for the given output or update stream via the stream’s underlying write function

Compilation
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Testing
1.interactive mode
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

2.non-interactive mode
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

`simple_shell.c` - carries the main function
`simple_shell.h` - headerr file
`display.c`

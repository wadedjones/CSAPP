/* Use execve to write a program called myls whose behavior is identical to /bin/ls */

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp) {
	if (execve("/bin/ls", argv, envp) == -1) {
		fprintf(stderr, "execve error: %s\n", strerror(errno));
		exit(1);
	}
	exit(0);
}

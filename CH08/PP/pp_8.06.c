/* write a program called myecho that prints its command-line arguments and environment variables */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv, char **envp) {

	printf("Command-line arguments:\n");
	for (int i = 0; i < argc; i++) {
		printf("argv[%d]: %s\n", i, argv[i]);
	}

	printf("Environment variables:\n");
	for (int i = 0; envp[i] != NULL; i++) {
		printf("envp[%d]: %.30s\n", i, envp[i]);
	}

	return 0;
}

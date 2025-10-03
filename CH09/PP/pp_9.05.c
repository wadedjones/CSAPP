/* Write a C program 'mmapcopy.c' that uses mmap to copy an arbitrary-size disk files to stdout.
* The name of the input file should be passed as a command-line argument */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

void *mmapcopy(int fd, size_t size) {
	void *buf = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
	write(STDOUT_FILENO, buf, size);
	return buf;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "usage: mmapcopy <filename>\n");
		exit(EXIT_FAILURE);
	}

	int fd;
	if ((fd = open(argv[1], O_RDONLY)) < 0) {
		fprintf(stderr, "cannot open file: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	struct stat st;
	if (fstat(fd, &st) < 0) {
		fprintf(stderr, "fstat error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	char *buf = mmapcopy(fd, st.st_size);

	printf("printing buf:\n%s\n", buf);

	return 0;
}

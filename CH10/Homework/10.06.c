/* what is the output of the following program? */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void) {
	int fd1, fd2;

	fd1 = open("foo.txt", O_RDONLY);
	fd2 = open("bar.txt", O_RDONLY);
	close(fd2);
	fd2 = open("baz.txt", O_RDONLY);
	printf("fd2 = %d\n", fd2);
	return 0;
}

/* what is the output of the following program? */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void) {
	int fd1, fd2;
	char c;

	fd1 = open("foobar.txt", O_RDONLY);
	fd2 = open("foobar.txt", O_RDONLY);
	read(fd2, &c, 1);
	dup2(fd2, fd1);
	read(fd1, &c, 1);
	printf("c = %c\n", c);
	return 0;
}

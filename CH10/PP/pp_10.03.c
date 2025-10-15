/* what is the output of the following program? */

#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void) {
	int fd;
	char c;

	fd = open("foobar.txt", O_RDONLY, 0);
	if (fork() == 0) {
		read(fd, &c, 1);
		return 0;
	}
	wait(NULL);
	read(fd, &c, 1);
	printf("c = %c\n", c);
	return 0;
}

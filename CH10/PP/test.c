#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
	struct stat st;
	int fd;
	char c;
	ssize_t rd;
	off_t offset;

	fd = open("foobar.txt", O_RDONLY);

	offset = lseek(fd, 0, SEEK_CUR);
	printf("offset: %ld\n", offset);

	while((rd = read(fd, &c, 1)) != 0 && c != EOF) {
		printf("%c\n", c == '\n' ? 'n' : c);
		offset = lseek(fd, 0, SEEK_CUR);
		printf("offset: %ld\n", offset);
	}

	return 0;
}

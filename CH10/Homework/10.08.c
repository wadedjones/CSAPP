#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	struct stat st;
	int fd = open(argv[1], O_RDONLY);
	char *type, *readok;

	fstat(fd, &st);
	if (S_ISREG(st.st_mode)) {
		type = "regular";
	} else if (S_ISDIR(st.st_mode)) {
		type = "directory";
	} else {
		type = "other";
	}

	if ((st.st_mode & S_IRUSR)) {
		readok = "yes";
	} else {
		readok = "no";
	}

	printf("type: %s, read: %s\n", type, readok);
	return 0;
}

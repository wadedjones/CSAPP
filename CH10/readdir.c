#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	DIR *streamp;
	struct dirent *dep;

	streamp = opendir(argv[1]);

	errno = 0;
	while ((dep = readdir(streamp)) != NULL) {
		printf("Found file: %s\n", dep->d_name);
	}
	if (errno != 0) {
		fprintf(stderr, "readdir error: %s\n", strerror(errno));
		return 1;
	}

	closedir(streamp);
	return 0;
}

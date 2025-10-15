#include "r_io.h"
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	int n;
	rio_t rio;
	char buf[MAXLINE];

	if (argc == 2) {
		int fd = open(argv[1], O_RDONLY);
		while ((n = rio_readn(fd, buf, MAXLINE)) != 0) {
			rio_writen(STDOUT_FILENO, buf, n);
			return 0;
		}
	}
	rio_readinitb(&rio, STDIN_FILENO);
	while ((n = rio_readlineb(&rio, buf, MAXLINE)) != 0) {
		rio_writen(STDOUT_FILENO, buf, n);
	}

	return 0;
}

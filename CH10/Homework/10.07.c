#include "r_io.h"

int main(int argc, char **argv) {
	int n;
	char buf[MAXLINE];

	while ((n = rio_readn(STDIN_FILENO, buf, MAXLINE)) != 0) {
		rio_writen(STDOUT_FILENO, buf, n);
	}

	return 0;
}

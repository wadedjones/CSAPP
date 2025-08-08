#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int my_ls(char **argv) {
    struct dirent *rdir;
    int verbose = 0;

    DIR *dr;

    if ((dr = opendir(".")) == NULL) {
        fprintf(stderr, "open dir: %s\n", strerror(errno));
        return -1;
    }

    if (argv[1] && argv[1][0] == '-' && argv[1][1] == 'v') {
        verbose = 1;
    }

    while ((rdir = readdir(dr)) != NULL) {
        if (!verbose && rdir->d_name[0] == '.') {
            continue;
        }
        printf("%s\n", rdir->d_name);
    }

    int d;
    if ((d = closedir(dr)) < 0) {
        fprintf(stderr, "close dir: %s\n", strerror(errno));
        return -1;
    }

    return 0;
}

int main(int argc, char **argv) {
	my_ls(argv);
	return 0;
}

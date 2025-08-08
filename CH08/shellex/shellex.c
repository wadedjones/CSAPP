/* program for a simple shell routine */

/* includes */
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* defines */
#define MAXLINE 8192
#define MAXARGS 10

/* prototypes */
void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);
pid_t Fork(void);
//int my_ls(char **argv);
char *safe_strcpy(char *dest, const char *src, size_t n);

/* global variables */
char **environ;

int main(void) {
    char cmdline[MAXLINE];

    while (1) {
        /* read */
        printf("> ");
        if (fgets(cmdline, MAXLINE, stdin) == NULL) {
            fprintf(stderr, "fgets\n");
            exit(1);
        }
        if (feof(stdin)) {
            exit(0);
        }

        /* evaluate */
        eval(cmdline);
    }
}

void eval(char *cmdline) {
    char *argv[MAXARGS]; /* argument list execve() */
    char buf[MAXLINE];   /* holds modified command line */
    int bg;              /* should the job run in bg or fg? */
    pid_t pid;           /* process id */

	size_t cmd_len = strlen(cmdline);
	safe_strcpy(buf, cmdline, cmd_len);
    // strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    if (argv[0] == NULL) {
        return; /* ignore empty lines */
    }

    if (!builtin_command(argv)) {
        if ((pid = Fork()) == 0) {
            if (execve(argv[0], argv, environ) < 0) {
                printf("%s: Command not found.\n", argv[0]);
                exit(1);
            }
        }
        if (!bg) {
            int status;
            if (waitpid(pid, &status, 0) < 0) {
                fprintf(stderr, "waitfg: waitpid error: %s\n", strerror(errno));
                exit(1);
            }
        } else {
            printf("%d %s", pid, cmdline);
        }
    }

    return;
}

int builtin_command(char **argv) {
    if (!strcmp(argv[0], "quit")) { /* quit command */
        exit(0);
    }
	// if (!strcmp(argv[0], "ls")) {
	// 	my_ls(argv);
	// 	return 1;
	// }
    if (!strcmp(argv[0], "&")) { /* ignore singleton & */
        return 1;
    }
    return 0; /* not a builtin command */
}

int parseline(char *buf, char **argv) {
    char *delim; /* points to first space delimiter */
    int argc;    /* number of args */
    int bg;      /* background job? */

    buf[strlen(buf) - 1] = ' ';     /* replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) { /* ignore leading spaces */
        buf++;
    }

    /* build the argv list */
    argc = 0;
    while ((delim = strchr(buf, ' '))) {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' ')) { /* ignore spaces */
            buf++;
        }
    }

	argv[argc] = NULL;

	if (argc == 0) { /* ignore blank line */
		return 1;
	}

	/* should the job run in the background? */
	if ((bg = (*argv[argc - 1] == '&')) != 0) {
		argv[--argc] = NULL;
	}

	return bg;
}

pid_t Fork(void) {
    pid_t pid;

    if ((pid = fork()) < 0) {
        fprintf(stderr, "fork error: %s\n", strerror(errno));
        exit(1);
    }

    return pid;
}

// int my_ls(char **argv) {
// 	struct dirent *rdir;
// 	int verbose = 0;
//
// 	DIR *dr;
//
// 	if ((dr = opendir(".")) == NULL) {
// 		fprintf(stderr, "open dir: %s\n", strerror(errno));
// 		return -1;
// 	}
//
// 	if (argv[1] && argv[1][0] == '-' && argv[1][1] == 'v') {
// 		verbose = 1;
// 	}
//
// 	while ((rdir = readdir(dr)) != NULL) {
// 		if (!verbose && rdir->d_name[0] == '.') {
// 			continue;
// 		}
// 		printf("%s\n", rdir->d_name);
// 	}
//
// 	int d;
// 	if ((d = closedir(dr)) < 0) {
// 		fprintf(stderr, "close dir: %s\n", strerror(errno));
// 		return -1;
// 	}
//
// 	return 0;
// }

char *safe_strcpy(char *dest, const char *src, size_t n) {
	if (n <= 0) {
		return NULL;
	}

	size_t i;
	for (i = 0; i < n && src[i]; i++) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return dest;
}

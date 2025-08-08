/* using the waitpid function to reap zombie children in no particular order */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 10

pid_t Fork(void) {
    pid_t pid;

    if ((pid = fork()) < 0) {
        fprintf(stderr, "fork error: %s\n", strerror(errno));
        exit(0);
    }
    return pid;
}

int main(void) {
    int status, i;
    pid_t pid;

    /* parent creates N children */
    for (i = 0; i < N; i++) {
        if ((pid = Fork()) == 0) { /* child */
            exit(100 + i);
        }
    }

    /* parent reaps N children in no particular order */
    while ((pid = waitpid(-1, &status, 0)) > 0) {
        if (WIFEXITED(status)) {
            printf("child %d terminated normally with exit status(%d)=%d\n",
                   pid, status, WEXITSTATUS(status));
        } else {
            printf("child %d terminated abnormally\n", pid);
        }
    }

    /* the only normal termination is if there are no more children */
    if (errno != ECHILD) {
        fprintf(stderr, "waitpid error: %s\n", strerror(errno));
        exit(0);
    }

    exit(0);
}

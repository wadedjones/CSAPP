#include "csapp_h/csapp.h"

void addjob(pid_t);
void deletejob(pid_t);
void initjobs(void);

void handler(int sig) {
	int olderrno = errno;
	sigset_t mask_all, prev_all;
	pid_t pid;

	Sigfillset(&mask_all);
	while ((pid = waitpid(-1, NULL, 0)) > 0) { /* Reap a zombie child */
		Sigprocmask(SIG_BLOCK, &mask_all, &prev_all);
		/* deletejob() will be defined in the "lab" */
		deletejob(pid);
		Sigprocmask(SIG_SETMASK, &prev_all, NULL);
	}
	if (errno != ECHILD) {
		Sio_error("waitpid error");
	}
	errno = olderrno;
}

int main(int argc, char **argv) {
	int pid;
	sigset_t mask_all, mask_one, prev_one;

	Sigfillset(&mask_all);
	Sigemptyset(&mask_one);
	Sigaddset(&mask_one, SIGCHLD);
	Signal(SIGCHLD, handler);
	/* initjobs() will be defined in the "lab" */
	initjobs(); // Initialize the job list
	
	while (1) {
		Sigprocmask(SIG_BLOCK, &mask_one, &prev_one); /* Block SIGCHLD */
		if ((pid = Fork()) == 0) { /* Child process */
			Sigprocmask(SIG_SETMASK, &prev_one, NULL); /* Unblock SIGCHLD */
			Execve("/bin/date", argv, NULL);
		}
		Sigprocmask(SIG_BLOCK, &mask_all, NULL); /* Parent process */
		/* addjob() will be defined in the "lab" */
		addjob(pid); /* Add the child to the job list */
		Sigprocmask(SIG_SETMASK, &prev_one, NULL); /* Unblock SIGCHLD */
	}
	exit(0);
}

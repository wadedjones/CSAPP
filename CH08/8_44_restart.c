#include "csapp_h/csapp.h" // IWYU pragma: keep

sigjmp_buf buf;

void handler(int sig) {
	siglongjmp(buf, 1);
}

int main(void) {
	if (!sigsetjmp(buf, 1)) {
		Signal(SIGINT, handler);
		Sio_puts("starting\n");
	} else {
		Sio_puts("restarting\n");
	}

	while (1) {
		Sleep(1);
		Sio_puts("processing...\n");
	}

	exit(0); /* Control never reaches here */
}

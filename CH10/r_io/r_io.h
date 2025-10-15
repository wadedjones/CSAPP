#ifndef R_IO_H
#define R_IO_H
#include <unistd.h>

#define RIO_BUFSIZE 8192

typedef struct {
	int rio_fd;					/* descriptor for this internal buf */
	int rio_cnt;				/* unread bytes in internal buf */
	char *rio_bufptr;			/* next unread byte in internal buf */
	char rio_buf[RIO_BUFSIZE];	/* internal buffer */
} rio_t;

/* Returns: number of bytes transferred if OK, 0 on EOF, -1 on error */
ssize_t rio_readn(int fd, void *usrbuf, size_t n);

/* Returns: number of bytes transferred if OK, -1 on error */
ssize_t rio_writen(int fd, void *usrbuf, size_t n);

/* initializes rio_t *rp struct */
void rio_readinitb(rio_t *rp, int fd);

/* Returns: number of bytes read if OK, 0 on EOF, -1 on error */
ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);

/* Returns: number of bytes read if OK, 0 on EOF, -1 on error */
ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n);

#endif

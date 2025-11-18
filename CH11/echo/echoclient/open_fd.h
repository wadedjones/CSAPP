#ifndef OPEN_FD_H
#define OPEN_FD_H

#define MAXLINE 1024
#define LISTENQ 1024

int open_clientfd(char *hostname, char *port);
int open_listenfd(char *port);

#endif

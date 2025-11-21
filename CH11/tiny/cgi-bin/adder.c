#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAXLINE 8192

void slice(const char *str, char *result, size_t start) {
	strcpy(result, str + start);
}

int main(void) {
	char *buf;
	char *p;
	char content[MAXLINE];
	int n1 = 0;
	int n2 = 0;

	/* extract the two arguments */
	if ((buf = getenv("QUERY_STRING")) != NULL) {
		p = strchr(buf, '&');
		*p++ = '\0';
		buf = strchr(buf, '=');
		p = strchr(p, '=');
		n1 = atoi(buf + 1);
		n2 = atoi(p + 1);
	}

	/* make the response body */
	sprintf(content, "QUERY_STRING=%s", buf);
	sprintf(content, "Welcome to add.com: ");
	sprintf(content, "%sTHE internet addition portal.\r\n<p>", content);
	sprintf(content, "%sThe answer is: %d + %d = %d\r\n<p>", content, n1, n2, n1 + n2);
	sprintf(content, "%sThanks for visiting!\r\n", content);

	/* generate the HTTP response */
	printf("Connection: close\r\n");
	printf("Content-length: %d\r\n", (int)strlen(content));
	printf("Content-type: text/html\r\n\r\n");
	printf("%s", content);
	fflush(stdout);
	
	exit(0);
}

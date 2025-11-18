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
	char arg1[MAXLINE];
	char arg2[MAXLINE];
	char arg1slice[MAXLINE];
	char arg2slice[MAXLINE];
	char content[MAXLINE];
	int n1 = 0;
	int n2 = 0;

	/* extract the two arguments */
	if ((buf = getenv("QUERY_STRING")) != NULL) {
		printf("QUERY_STRING: %s\n", buf);
		p = strchr(buf, '&');
		*p = '\0';
		strcpy(arg1, buf);
		/* num1=123 */
		slice(arg1, arg1slice, 5);
		strcpy(arg2, p + 1);
		slice(arg2, arg2slice, 5);
		n1 = atoi(arg1slice);
		n2 = atoi(arg2slice);
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

/* Write a function good_echo that reads a line from standard input and writes it to standard output */

#include <stdio.h>
#include <stdlib.h>

int good_echo(void);
void good_echo_alt(void);

int main(void) {
	char c;
	while((c = good_echo()) && c != EOF)
		;
	// good_echo_alt();
	return 0;
}

int good_echo(void) {
	size_t len = 1024;
	size_t i = 0;
	char *buf = malloc(sizeof(buf) * len);
	char c;
	while ((c = fgetc(stdin)) && c != EOF) {
		if (i == len) {
			buf = realloc(buf, len * 2);
			len *= 2;
		}
		if (c == '\n') {
			break;
		}
		buf[i++] = c;
	}
	buf[i] = 0;

	printf("%s\n", buf);

	return c;
}

void good_echo_alt(void) {
	char buf[12];
	while(1) {
		char *p = fgets(buf, 12, stdin);
		if (!p) {
			break;
		}
		printf("%s", p);
	}
	return;
}

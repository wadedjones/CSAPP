#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *fp;
    char c;
    size_t line = 1;

    if (argc == 1) {
        fp = stdin;
		printf("%ld ", line++);
        while ((c = getc(fp)) != EOF) {
			if (c == '\n') {
				putc(c, stdout);
				printf("%ld ", line++);
			} else {
				putc(c, stdout);
			}
        }
		printf("\n");
    } else {
        for (int i = 1; i < argc; i++) {
            if ((fp = fopen(argv[i], "r")) == NULL) {
                fp = stdin;
            }
			printf("%ld ", line++);
            while ((c = getc(fp)) != EOF) {
				if (c == '\n') {
					putc(c, stdout);
					printf("%ld ", line++);
				} else {
					putc(c, stdout);
				}
            }
        }
		printf("\n");
    }

    return 0;
}


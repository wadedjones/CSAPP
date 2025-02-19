/* example code of slow lower case conversion with faster version */
#include <stdio.h>

size_t _strlen(const char *str) {
	size_t len = 0;
	for (; *str != '\0'; str++) {
		len++;
	}
	return len;
}

/* calling _strlen inside the loop slows it down */
void lower1(char *str) {
	size_t i;
	for (i = 0; i < _strlen(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] -= ('A' - 'a');
		}
	}
}

/* calling it outside the loop speeds it up
* also I'm converting 'A' - 'a' to a variable
*/
void lower2(char *str) {
	size_t i;
	size_t len = _strlen(str);
	int amt_to_lower = 'A' - 'a';
	for (i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] -= amt_to_lower;
		}
	}
}

int main(void) {
	char str1[] = "HElLo 123";
	char str2[] = "GOOdbYE 456";

	lower1(str1);
	lower2(str2);

	printf("%s\n", str1);
	printf("%s\n", str2);

	return 0;
}

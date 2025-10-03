#include "memlib.h"
#include <string.h>
#include <stdint.h>

typedef struct s1 {
	uint8_t age;
	uint8_t ssn;
	char name[255];
} s1;

s1 *init_s1(uint8_t age, uint8_t ssn, char *name) {
	s1 *result = (s1 *)mm_malloc(sizeof(*result));
	result->age = age;
	result->ssn = ssn;
	strncpy(result->name, name, strlen(name));

	return result;
}

void p_s1(s1 *person) {
	printf("age: %d, ssn: %d, name: %s\n", person->age, person->ssn, person->name);
}

int main(void) {
	mem_init();
	mm_init();

	s1 *p1 = init_s1(37, 255, "Wade");
	s1 *p2 = init_s1(38, 69, "Jones");

	p_s1(p1);
	p_s1(p2);

	mm_free(p1);
	mm_free(p2);

	return 0;
}

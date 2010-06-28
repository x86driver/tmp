#include <stdio.h>
#include <stdlib.h>

#define SEL0 0

struct A {
	unsigned char buf[512];
	unsigned char *ptr;
};

int main()
{
	struct A *a;
	a = (struct A*)malloc(sizeof(struct A));

	a->ptr = &a->buf[0];

	switch (*a->ptr++) {
		case SEL0:
			printf("HI\n");
			break;
		default:
			break;
	}
	return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct A {
	int buf[512];
};

struct A *a;

int main()
{
	int ret = posix_memalign((void**)&a, 64, sizeof(struct A));
	printf("%d\n", ret);
	a->buf[0] = 10;
	printf("%d\n", a->buf[0]);
	free(a);
	return 0;
}

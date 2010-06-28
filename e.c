#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct ARR {
	uint32_t buf[16];
};

struct A {
	struct ARR arr;
};

register struct A *a asm("r12");

void __attribute__((noinline)) add()
{
//	a->arr.buf[0]++;
//	a->arr.buf[1] = 7;
	a->arr.buf[3] = a->arr.buf[1] + a->arr.buf[2];
}

uint8_t offset(uint64_t r0)
{
	return (uint64_t)(&a->arr.buf[r0])-(uint64_t)a;
}

int main()
{
	a = malloc(sizeof(struct A));

	printf("%d\n", a->arr.buf[0]);
	printf("%d\n", (uint64_t)(&a->arr.buf[1])-(uint64_t)a);
	free(a);
	return 0;
}

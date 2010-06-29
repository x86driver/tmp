#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

uint32_t map = 0xffffffff;

inline uint32_t __attribute__((inline)) alloc()
{
	uint32_t ret;
	__asm__ ("bsr %1, %0\n\t"\
		"btr %0, %1\n\t"
		:"=r"(ret):"m"(map));

	return ret;
}

int main()
{
	int i;
	for (i = 0; i < 32; ++i) {
		uint32_t r = alloc();
		printf("%d\n", r);
		printf("map: 0x%x\n", map);
	}
	return 0;
}

int main2()
{
	srand(time(0));
	int i;
	for (i = 0; i < 3; ++i) {
		uint32_t opdst = rand() % 16;
		uint32_t oprm = rand() % 16;
		printf("mov r%d, %d\n", opdst, oprm);
	}
	return 0;
}

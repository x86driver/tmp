#include <stdio.h>
#include <stdint.h>

static uint32_t map = 0xffffffff;

uint32_t __attribute__((noinline)) alloc()
{
	uint32_t ret;
	__asm__ ("bsr %0, %1\n\t"\
		"btr %1, %0\n\t"
		:"=r"(map), "=r"(ret));

	return ret;
}

int main()
{
	int i;
//	for (i = 0; i < 32; ++i) {
	uint32_t r = alloc();
		printf("%d\n", r);
		printf("map: 0x%x\n", map);

		r = alloc();
                printf("%d\n", r);
                printf("map: 0x%x\n", map);

//	}
	return 0;
}

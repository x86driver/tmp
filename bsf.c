#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define EAX 0x0b8
#define ECX 0x0b9
#define EDX 0x0ba
#define EBX 0x0bb
#define ESP 0x0bc
#define EBP 0x0bd
#define ESI 0x0be
#define EDI 0x0bf
#define R8  0x041b8
#define R9  0x041b9
#define R10 0x041ba
#define R11 0x041bb
#define R12 0x041bc
#define R13 0x041bd
#define R14 0x041be
#define R15 0x041bf

uint32_t map = 0xffffffff;

inline uint32_t alloc()
{
	uint32_t ret;
	__asm__ ("bsf %1, %0\n\t"\
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

        static unsigned int regmap[16] = {0};
        uint32_t regtbl[16] = {EAX, ECX, EDX, ESI, EDI, R8, R9, R10,
                        R11, EBX, EBP, ESP, R13, R14, R15}; /* No R12 */

	for (i = 0; i < 16; ++i) {
		uint32_t opdst = rand() % 16;
		uint32_t oprm = rand() % 16;
		if (regmap[opdst] == 0) {
			regmap[opdst] = regtbl[alloc()];
		}
		printf("mov r%d, r%d\t; r%d => 0x%x\n", opdst, oprm, opdst, regmap[opdst]);

	}
	return 0;
}

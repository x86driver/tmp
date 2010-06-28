#include <stdio.h>

int main()
{
	__asm__ ("mov r2, #0\n\t"\
		"mov r1, r1\n\t"\
		"mov r3, r2\n\t"\
		".1: tst r3, #1\n\t"\
		"add r3, r3, #1\n\t"\
		"addeq r2, r2, #1\n\t"\
		"addne r1, r1, #1\n\t"\
		"cmp r3, #1000\n\t"\
		"bne .1\n\t"
	);
	return 0;
}

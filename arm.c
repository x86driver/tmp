#include <stdio.h>

int main()
{
	__asm__ ("mov r0, #5\n\t"
		"mov r1, r0\n\t"
		"mov r2, r1\n\t"
		"mov r3, r2\n\t"
		"mov r4, r3\n\t"
		"mov r5, r4\n\t"
		"mov r6, r5\n\t"
		"mov r7, r6\n\t"
		"mov r8, r7\n\t"
		"mov r9, r8\n\t"
		"mov r10, r9\n\t"
		"mov r11, r10\n\t"
		"mov r12, r11\n\t"
		"mov r13, r12\n\t"
		"mov r14, r13\n\t"
		"mov r15, r14\n\t"
	);
	return 0;
}

int main2()
{
	__asm__ ("mov r10, #7\n\t"
		"ldr r11, [r10]\n\t"
	);
	return 0;
}

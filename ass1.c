#include <stdio.h>

void test()
{
	__asm__ volatile("mov %r0, #10\n\t"
			"mov %r1, #10\n\t"
			"mov %r2, #10\n\t"
			"mov %r3, #10\n\t"
			"mov %r4, #10\n\t"
			"mov %r5, #10\n\t"
			"mov %r6, #10\n\t"
			"mov %r7, #10\n\t"
			"mov %r8, #10\n\t"
			"mov %r9, #10\n\t"
			"mov %r10, #10\n\t"
			"mov %r11, #10\n\t"
			"mov %r12, #10\n\t"
			"mov %r13, #10\n\t"
			);
}

void test2()
{
	char buf[] = {1,2,3,4,5,6};
	int i;
	__asm__ volatile("mov lr, #10\n\t":::"lr");
	for (i = 0; i < 5; ++i) {
		if (buf[i] +buf[i+1] == 5)
			printf("Yes");
	}
}

int main()
{
	test();
	test2();
	return 0;
}

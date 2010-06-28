#include <stdio.h>

void __attribute__((noinline)) func()
{
//	__asm__("movl $0, %esp");
}

int main()
{
	int a = 10;
	func();
	printf("a = %d\n", a);
	return 0;
}

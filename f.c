#include <stdio.h>

void __attribute__((noinline)) set()
{
	printf("Hi");
}

int main()
{
	unsigned int i = 0;
	unsigned int a = 0, b = 0;

	for (i = 0; i < 1000; ++i) {
		if (i % 2)
			++a;
		else
			++b;
	}

	printf("a = %d, b = %d\n", a, b);
	return 0;
}

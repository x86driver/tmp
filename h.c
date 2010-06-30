#include <stdio.h>

struct item {
	int count;
};

struct A {
	struct item it;
};

struct A a = {.it = {.count = 10}};

int main()
{
	printf("%d\n", a.it.count);
	return 0;
}

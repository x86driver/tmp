#include <stdio.h>
#include <stdint.h>
#include <string.h>

void show()
{
	printf("Hello world\n");
}

int main()
{
	void(*func)(void);
	uint64_t parm[512];

	memset((void*)&parm[0], 0, sizeof(parm));

	*(void(**)(void))parm = show;

	printf("%d\n", sizeof(void(*)(void)));
	return 0;
}


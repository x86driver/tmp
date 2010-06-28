#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	uint32_t buf[512];
	uint32_t *ptr = &buf[0];

	printf("%p\n", ptr);
	*ptr++ = 10;
	printf("%p\n", ptr);

	printf("0x%x\n", &buf[0]);

	pid_t pid = getpid();
	char cmd[512];
	sprintf(cmd, "cat /proc/%d/maps", pid);
	system(cmd);
	return 0;
}

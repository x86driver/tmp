#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int *ptr = malloc(1024*1024*1024);
	printf("%p\n", ptr);
	memset(ptr, 0x65, 65536);
	printf("%d\n", *(ptr+8192));
        pid_t pid = getpid();
        char cmd[512];
        sprintf(cmd, "cat /proc/%d/maps", pid);
        system(cmd);

	free(ptr);
}


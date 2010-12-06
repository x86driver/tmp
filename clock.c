#include <stdio.h>
#include <time.h>

int main()
{
	struct timespec t;
	struct tm *tm;
	clock_gettime(CLOCK_REALTIME, &t);
	tm = localtime(&t.tv_sec);
	printf("%d:%d:%d\n", tm->tm_hour, tm->tm_min, tm->tm_sec);
	return 0;
}


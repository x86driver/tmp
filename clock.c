#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	struct timespec t;
	struct tm *tm = malloc(sizeof(struct tm));
        tm->tm_year = 110;
        tm->tm_mon = 11;
        tm->tm_mday = 6;
        tm->tm_hour = 16;
        tm->tm_min = 5;
        tm->tm_sec = 0;
        tm->tm_wday = 1;
        tm->tm_yday = 339;
        tm->tm_isdst = 0;
        t.tv_sec = mktime(tm);
        free(tm);
	clock_settime(CLOCK_REALTIME, &t);
//        clock_gettime(CLOCK_REALTIME, &t);
	tm = localtime(&t.tv_sec);

	printf("%d/%d/%d %d:%d:%d, wday:%d, yday:%d, isdst: %d\n",
                tm->tm_year, tm->tm_mon, tm->tm_mday,
                tm->tm_hour, tm->tm_min, tm->tm_sec,
                tm->tm_wday, tm->tm_yday, tm->tm_isdst);

	return 0;
}


#include <stdio.h>

static void itoa(char *buf, unsigned int val)
{
	int i;
	buf += 10;
	*buf-- = '\0';
	for (i = 0; i < 8; ++i) {
		if ((val % 16) > 9)
			*buf-- = (val % 16) - 10 + 'A';
		else
			*buf-- = (val % 16) + '0';
		val /= 16;
	}
	*buf-- = 'x';
	*buf-- = '0';
}

int main()
{
	char buf[11];
	unsigned int val = 0xabcd123f;
	itoa(buf, val);
	printf("%s\n", buf);
	return 0;
}


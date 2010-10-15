#include <stdio.h>

int curve( double x )
{
#if 0
	static const double a = -1.21713988718776E-10;
	static const double b = 2.15024245270835E-06;
	static const double c = -1.51850253641268E-02;
	static const double d = 53.58380304401;
	static const double e = -94479.8660633283;
	static const double f = 66591617.123341 + 0.5;

	static const double a = -0.000000000121713988718776;
	static const double b = 0.00000215024245270835;
	static const double c = -0.0151850253641268;

	printf("a = %20.20f\n", a);
	printf("b = %f\n", b);
	printf("c = %f\n", c);
	printf("d = %f\n", d);
	printf("e = %f\n", e);
	printf("f = %f\n", f);
#endif

	static const double a = -1.2171399E-10;
	static const double b = 2.1502424E-06;
	static const double c = -0.0151850255;
	static const double d = 53.5838;
	static const double e = -94479.87;
	static const double f = 6.6591616E7;

	return( (int)( ( ( ( ( a * x + b ) * x + c ) * x + d ) * x + e ) * x + f ) );
}

int main()
{
	double x = 3000.0;
	int cap = 0;
	for (; x < 4100.0; x += 10.0) {
		cap = curve(x);
		printf("Voltage: %f --> %d%%\n", x, cap);
	}

	return 0;
}

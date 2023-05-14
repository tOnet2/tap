#include <stdio.h>

double power(double a, int n);

int main()
{
	int n;
	double a;
	scanf("%lf%d", &a, &n);
	if (a < 0) {
		printf("input a >= 0, n >= 1");
	}
	double res = power(a, n);
	printf("%.40lf\n", res);
	return 0;
}

double power(double a, int n)
{
	if (!n) {
		return 1;
	}
	if (n < 0) {
		return 1 / a * power(a, n + 1);
	} else {
		return a * power(a, n - 1);
	}
}

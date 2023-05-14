#include <stdio.h>

double power(double a, int n);

int main()
{
	int n;
	double a, res;
	scanf("%lf%d", &a, &n);
	if (a < 0 || n < 1) {
		printf("input a >= 0, n >= 1");
	}
	if (!(n % 2)) {
		res = power(a * a, n / 2);
	} else {
		res = a * power(a, n - 1);
	}
	printf("%.40lf\n", res);
	return 0;
}

double power(double a, int n)
{
	if (n == 1) {
		return a;
	}
	return a * power(a, n - 1);
}

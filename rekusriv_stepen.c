#include <stdio.h>

double rekursiv_stepen(double a, int n);

int main()
{
	int n;
	double a;
	scanf("%lf%d", &a, &n);
	if (n < 1 || a < 0) {
		printf("input a >= 0, n >= 1");
	}
	double res = rekursiv_stepen(a, n);
	printf("%.6lf\n", res);
	return 0;
}

double rekursiv_stepen(double a, int n)
{
	if (n == 1) {
		return a;
	}
	return a * rekursiv_stepen(a, n - 1);
}

#include <stdio.h>
#include <time.h>

int fibonaci(int n);
int fibonaci_1(int n);

int main()
{
	time_t beg, end;
	double ft, f_1t;
	int n, f, f_1;
	scanf("%d", &n);
	if (n < 1 || n > 40) {
		printf("1 <= n <= 40");
		return 1;
	}

	beg = clock();
	f = fibonaci(n);
	end = clock();
	ft = (double)(end - beg) / CLOCKS_PER_SEC * 1000;

	beg = clock();
	f_1 = fibonaci_1(n);
	end = clock();
	f_1t = (double)(end - beg) / CLOCKS_PER_SEC * 1000;

	printf("rekursiv = %d, time = %lfms\n", f, ft);
	printf("bez rekursii = %d, time = %lfms\n", f_1, f_1t);

	return 0;
}

int fibonaci(int n)
{
	if (n == 1 || n == 2) {
		return 1;
	}
	return fibonaci(n - 1) + fibonaci(n - 2);
}

int fibonaci_1(int n)
{
	int res;
	int a[2] = {0, 1};
	while (n-- > 1) {
		res = a[0] + a[1];
		a[0] = a[1];
		a[1] = res;
	}
	return a[1];
}

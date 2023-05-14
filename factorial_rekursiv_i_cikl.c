#include <stdio.h>
#include <time.h>

unsigned long factorial(const unsigned long n);
unsigned long factorial_1(unsigned long n);

int main()
{
	time_t beg, end;
	unsigned long n, f, f_1;
	double f_time, f_1_time;
	scanf("%ld", &n);
	if (n < 1) {
		printf("n >= 1");
		return 1;
	}

	beg = clock();
	f = factorial((const unsigned long)n);
	end = clock();
	f_time = (double)(end - beg) / CLOCKS_PER_SEC * 1000;

	beg = clock();
	f_1 = factorial_1(n);
	end = clock();
	f_1_time = (double)(end - beg) / CLOCKS_PER_SEC * 1000;

	printf("rekursiv = %lu, vremya = %lfms\n", f, f_time);
	printf("bez rekursii = %lu, vremya = %lfms\n", f_1, f_1_time);
	return 0;
}

unsigned long factorial(const unsigned long n)
{
	if (n == 1) {
		return 1;
	}
	return n * factorial(n - 1);
}

unsigned long factorial_1(unsigned long n)
{
	unsigned long res = 1;
	while (n) {
		res *= n--;
	}
	return res;
}

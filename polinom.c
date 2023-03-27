#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdlib.h>

int32_t main()
{
	srand(time(NULL));
	int32_t nn, n, remember_n;
	int64_t x = 55;
	int64_t coefs[100000];
	int64_t res = 0;
	int64_t xx;
	scanf("%d", &n);
	if (n < 1) {
		printf("n >= 1\n");
		exit(1);
	}
	remember_n = n;
	size_t i = 0;
	for (; i <= n; i++)
		coefs[i] = rand() % 21 - 10; // получаем случайные коэфициенты от -10 до 10
	clock_t begin, end;
	begin = clock(); // ------------------ в лоб
	for (; n > 0; n--) {
		xx = x;
		nn = n;
		for (; nn > 1; nn--)
			xx *= x;
		res += coefs[n]*xx;
	}
	res += coefs[n];
	end = clock(); // -------------------- в лоб
	printf("%ld %gs\n----------\n", res, (double)(end-begin) / CLOCKS_PER_SEC);
	
	n = remember_n;
	begin = clock(); // ------------------ накопление степени
	res = coefs[0];
	int64_t power = 1;
	for (i = 1; i <= n; i++) {
		power *= x;
		res += power * coefs[i];
	}
	end = clock(); // -------------------- накопление степени
	printf("%ld %gs\n----------\n", res, (double)(end-begin) / CLOCKS_PER_SEC);

	begin = clock(); // ------------------ схема Горнера
	res = coefs[n] * x + coefs[n - 1];
	n -= 2;
	for (; n >=0; n--)
		res = res * x + coefs[n];
	end = clock(); // -------------------- схема Горнера
	printf("%ld %gs\n----------\n", res, (double)(end-begin) / CLOCKS_PER_SEC);
	return 1;
}












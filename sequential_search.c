#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>

int *random_array(const int l);
int sequential_search_pos(const int *arr, const int arr_length, const int num);

int main()
{
	int n, x, *arr, pos;
	srand(time(NULL));
	printf("n: ");
	scanf("%d", &n);
	if (n < 100 || n > 1000) {
		printf("100 < n < 1000\n");
		return 1;
	}
	printf("x: ");
	scanf("%d", &x);
	if (x > n || x < 1) {
		printf("1 <= x <= n\n");
		return 1;
	}
	arr = random_array((const int)n);
	if (!arr) {
		fprintf(stderr, "malloc array, %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
#if 0 /* set 1 instead 0 to see numbers within the array */
	size_t i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	putchar('\n');
#endif
	if ((pos = sequential_search_pos((const int*)arr, (const int) n, (const int)x)) < 0) {
		printf("No element %d in array\n", x);
	} else {
		printf("position: %d\n", pos);
	}
	return 0;
}

int *random_array(const int l)
{
	int *arr = (int*)malloc(sizeof(int) * (size_t)l);
	if (!arr) {
		return NULL;
	}
	size_t i;
	for (i = 0; i < l; i++) {
		arr[i] = rand() % l + 1;
	}
	return arr;
}

int sequential_search_pos(const int *arr, const int arr_length, const int num)
{
	size_t i;
	for (i = 0; i < arr_length; i++) {
		if (arr[i] == num) {
			return i;
		}
	}
	return -1;
}

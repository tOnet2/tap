#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>

int *random_array(const int l);
void print_array(const int *arr, int arr_length);
void two_highs_and_positions(int arr_two_highs[4], const int *arr, const int arr_length);

int main()
{
	int n, *arr, arr_two_highs[4]; /* 
									* arr_two_highs contains:
									* [0] - first high, [1] - first high position,
									* [2] - second high, [3] - second high position
									*/ 
	srand(time(NULL));
	printf("n: ");
	scanf("%d", &n);
	if (n < 100 || n > 1000) {
		printf("100 < n < 1000\n");
		return 1;
	}
	arr = random_array((const int)n);
	if (!arr) {
		fprintf(stderr, "malloc array, %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
#if 0 /* set 1 instead 0 to see numbers within the array */
	print_array((const int*)arr, n);
#endif
	two_highs_and_positions(arr_two_highs, (const int*)arr, (const int)n);
	printf("First: %d\nFirst position: %d\nSecond: %d\nSecond position: %d\n",
			arr_two_highs[0], arr_two_highs[1], arr_two_highs[2], arr_two_highs[3]);
	return 0;
}

int *random_array(const int l)
{
	int *arr = (int*)malloc(sizeof(int) * (size_t)l);
	size_t i;
	if (!arr) {
		return NULL;
	}
	for (i = 0; i < l; i++) {
		arr[i] = rand() % l + 1;
	}
	return arr;
}

void print_array(const int *arr, int arr_length)
{
	while (arr_length--) {
		printf("%d ", *arr++);
	}
	putchar(0xa);
}

void two_highs_and_positions(int arr_two_highs[4], const int *arr, const int arr_length)
{
	size_t i;
	arr_two_highs[0] = 1;
	arr_two_highs[2] = 1;
	for (i = 0; i < arr_length; i++) {
		if (arr[i] >= arr_two_highs[0]) {
			arr_two_highs[0] = arr[i];
			arr_two_highs[1] = (int)i;
		} else if (arr[i] > arr_two_highs[2]) {
			arr_two_highs[2] = arr[i];
			arr_two_highs[3] = (int)i;
		}
	}
}

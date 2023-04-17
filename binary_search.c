#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

int *random_array(const size_t length);
void print_array(const int *arr, size_t arr_length);
void selection_sort(int *arr, const size_t arr_length);
size_t remove_repeats(int *sorted_arr, const size_t arr_length);
size_t binary_search(const int *arr, const size_t arr_length, const size_t num);

int main()
{
	size_t n, x, pos, sorted_arr_length;
	int *arr;
	srand(time(NULL));
	printf("n: ");
	scanf("%lu", &n);
	if (n < 100 || n > 1000) {
		printf("100 <= n <= 1000\n");
		return 1;
	}
	printf("x: ");
	scanf("%lu", &x);
	if (x > n || x < 1) {
		printf("1 <= x <= n\n");
		return 1;
	}
	arr = random_array((const int)n);
	if (!arr) {
		fprintf(stderr, "malloc array, %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
#if 0 /* set 1 instead 0 to see numbers within the array after init, after sort and after removing repeats */
	print_array((const int*)arr, n);
	printf("-----\n");
	selection_sort(arr, (const size_t)n);
	print_array((const int*)arr, n);
	printf("-----\n");
	sorted_arr_length = remove_repeats(arr, (const size_t)n);
	print_array((const int*)arr, sorted_arr_length);
	printf("-----\n");
#endif
	if ((pos = binary_search((const int*)arr, (const size_t)sorted_arr_length, (const size_t)x)) == sorted_arr_length ) {
		printf("No element %lu in array\n", x);
	} else {
		printf("position: %lu\n", pos);
	}
	return 0;
}

int *random_array(const size_t length)
{
	int *arr = (int*)malloc(sizeof(int) * length);
	size_t i;
	if (!arr) {
		return NULL;
	}
	for (i = 0; i < length; i++) {
		arr[i] = ((size_t)rand()) % length + 1;
	}
	return arr;
}

void print_array(const int *arr, size_t arr_length)
{
	while (arr_length--) {
		printf("%d ", *arr++);
	}
	putchar(0xa);
}

void selection_sort(int *arr, const size_t arr_length)
{
	size_t i, j, f;
	int min;
	for (i = 0; i < arr_length - 1; i++) {
		min = INT_MAX;
		for (j = i; j < arr_length; j++) {
			if (arr[j] < min) {
				min = arr[j];
				f = j;
			}
		}
		arr[f] = arr[i];
		arr[i] = min;
	}
}

size_t remove_repeats(int *sorted_arr, const size_t arr_length)
{
	size_t i, j;
	i = 0;
	for (j = 1; j < arr_length; j++) {
		if (sorted_arr[j] != sorted_arr[i]) {
			i++;
			sorted_arr[i] = sorted_arr[j];
		}
	}
	return i + 1;
}

size_t binary_search(const int *arr, const size_t arr_length, const size_t num)
{
	size_t l, r, mid;
	l = 0;
	r = arr_length - 1;
	while (l <= r) {
		mid = (r + l) / 2;
		if (arr[mid] == num) {
			return mid + 1;
		}
		if (num < arr[mid]) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return arr_length;
}

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int k, n, *arr, i, rand_num, tmp_num;
	scanf("%d%d", &k, &n); // получаем k и n
	if (k <= 1 || k >= n) {
		printf("1 < k < n\n");
		return 1;
	}
	if (n <= 1 || n >= 1000) {
		printf("1 < n < 1000\n");
		return 1;
	}
	size_t arr_length = n - k + 1;
	arr = (int*)malloc(sizeof(int) * arr_length); // делаем массив из (n - k + 1) элементов
	arr[0] = k;
	for (i = 1; i < arr_length; i++) // инициализируем массив
		arr[i] = arr[i - 1] + 1;
	for (i = arr_length - 1; i > 0; i--) { // цикл алгоритма
		rand_num = rand() % i; // получаем случайный номер элемента в массиве
		tmp_num = arr[i]; // меняем местами
		arr[i] = arr[rand_num];
		arr[rand_num] = tmp_num;
	}
	for (i = 0; i < arr_length; i++) { // печатаем результат
		printf("%d ", arr[i]);
	}
	putchar('\n');
	return 0;
}

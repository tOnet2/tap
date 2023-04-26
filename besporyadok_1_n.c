#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int n, *arr, i, rand_num, tmp_num;
	scanf("%d", &n);
	if (n <= 1 || n >= 1000) {
		printf("1 < n < 1000\n");
		return 1;
	}
	arr = (int*)malloc(sizeof(int) * n); // делаем массив из n элементов
	for (i = 0; i < n; i++) // инициализируем массив
		arr[i] = i + 1;
	for (i = n - 1; i > 0; i--) { // цикл алгоритма
		rand_num = rand() % i; // получаем случайный номер элемента в массиве
		tmp_num = arr[i]; // меняем местами
		arr[i] = arr[rand_num];
		arr[rand_num] = tmp_num;
	}
	for (i = 0; i < n; i++) { // печатаем результат
		printf("%d ", arr[i]);
	}
	putchar('\n');
	return 0;
}

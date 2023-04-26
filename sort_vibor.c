#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int n, *arr, i, j, rand_num, tmp_num, tmp_index;
	scanf("%d", &n);
	if (n <= 1 || n >= 1000) {
		printf("1 < n < 1000\n");
		return 1;
	}
	arr = (int*)malloc(sizeof(int) * n); // делаем массив из n элементов
	for (i = 0; i < n; i++) // инициализируем массив
		arr[i] = i + 1;
	for (i = n - 1; i > 0; i--) { // цикл алгоритма для беспорядка
		rand_num = rand() % i; // получаем случайный номер элемента в массиве
		tmp_num = arr[i]; // меняем местами
		arr[i] = arr[rand_num];
		arr[rand_num] = tmp_num;
	}
	for (i = 0; i < n; i++) // печатаем результат беспорядка
		printf("%d ", arr[i]);
	putchar('\n');

	for (i = 0; i < n - 1; i++) { // цикл алгоритма для сортировки выбором
		tmp_index = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[tmp_index])
				tmp_index = j;
		if (tmp_index != i) {
			tmp_num = arr[i];
			arr[i] = arr[tmp_index];
			arr[tmp_index] = tmp_num;
		}
		for (j = 0; j < n; j++) // печатаем после каждой итерации
			printf("%d ", arr[j]);
		putchar('\n');
	}
	return 0;
}

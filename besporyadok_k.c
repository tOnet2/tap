#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int k, n, *arr, i, j, rand_num, tmp_num;
	scanf("%d%d", &k, &n); // получаем k и n
	if (k <= 1 || k >= n) {
		printf("1 < k < n\n");
		return 1;
	}
	if (n <= 1 || n >= 1000) {
		printf("1 < n < 1000\n");
		return 1;
	}
	arr = (int*)malloc(sizeof(int) * k); // делаем массив из k элементов
	i = 0;
	while (i < k) { // инициализируем массив
		tmp_num = rand() % n + 1;
		for (j = 0; j < i; j++)
			if (arr[j] == tmp_num)
				break;
		if (j == i)
			arr[i++] = tmp_num;
	}
	for (i = k - 1; i > 0; i--) { // цикл алгоритма
		rand_num = rand() % i; // получаем случайный номер элемента в массиве
		tmp_num = arr[i]; // меняем местами
		arr[i] = arr[rand_num];
		arr[rand_num] = tmp_num;
	}
	for (i = 0; i < k; i++) { // печатаем результат
		printf("%d ", arr[i]);
	}
	putchar('\n');
	return 0;
}
